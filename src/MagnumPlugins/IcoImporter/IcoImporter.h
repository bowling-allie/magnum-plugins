#ifndef Magnum_Trade_IcoImporter_h
#define Magnum_Trade_IcoImporter_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Class @ref Magnum::Trade::IcoImporter
 */

#include <utility>
#include <Corrade/Containers/Array.h>
#include <Magnum/Trade/AbstractImporter.h>

#include "MagnumPlugins/IcoImporter/configure.h"

#ifndef DOXYGEN_GENERATING_OUTPUT
#ifndef MAGNUM_ICOIMPORTER_BUILD_STATIC
    #ifdef IcoImporter_EXPORTS
        #define MAGNUM_ICOIMPORTER_EXPORT CORRADE_VISIBILITY_EXPORT
    #else
        #define MAGNUM_ICOIMPORTER_EXPORT CORRADE_VISIBILITY_IMPORT
    #endif
#else
    #define MAGNUM_ICOIMPORTER_EXPORT CORRADE_VISIBILITY_STATIC
#endif
#define MAGNUM_ICOIMPORTER_LOCAL CORRADE_VISIBILITY_LOCAL
#else
#define MAGNUM_ICOIMPORTER_EXPORT
#define MAGNUM_ICOIMPORTER_LOCAL
#endif

namespace Magnum { namespace Trade {

/**
@brief ICO importer plugin
*/
class MAGNUM_ICOIMPORTER_EXPORT IcoImporter: public AbstractImporter {
    public:
        enum class ImageType : UnsignedShort {
            ICO = 1,
            CUR = 2
        };

        /** @brief Default constructor */
        explicit IcoImporter();

        /** @brief Plugin manager constructor */
        explicit IcoImporter(PluginManager::AbstractManager& manager, const std::string& plugin);

        ~IcoImporter() override;

    private:
        MAGNUM_ICOIMPORTER_LOCAL Features doFeatures() const override;
        MAGNUM_ICOIMPORTER_LOCAL bool doIsOpened() const override;
        MAGNUM_ICOIMPORTER_LOCAL void doClose() override;
        MAGNUM_ICOIMPORTER_LOCAL void doOpenData(Containers::ArrayView<const char> data) override;

        MAGNUM_ICOIMPORTER_LOCAL UnsignedInt doImage2DCount() const override;
        MAGNUM_ICOIMPORTER_LOCAL Containers::Optional<ImageData2D> doImage2D(UnsignedInt id) override;

        bool _isOpened = false;
        Containers::Pointer<Trade::AbstractImporter> _pngImporter = nullptr;
        Containers::Array<std::pair<bool, Containers::Array<char>>> _imageDataArray{};
};

}}

#endif
