//
// Created by DexrnZacAttack on 1/2/2025.
//

#include "LCE/color/Color.h"
#include "LCE/color/ColorFile.h"

namespace lce::color {
    Color::Color(const ARGB color) : color(color) {}

    Color::Color(std::vector<uint8_t> &data)
        : Color(bio::BinaryIO(data.data())) {}

    Color::Color(uint8_t *data) : Color(bio::BinaryIO(data)) {}

    Color::Color(bio::BinaryIO &&io) : Color(io) {}

    Color::Color(bio::BinaryIO &io) { this->color = io.readLE<ARGB>(); }

    size_t Color::getSize() const { return sizeof(ARGB); }

    uint8_t *Color::serialize() const {
        bio::BinaryIO io(getSize());

        io.writeLE<ARGB>(color);

        return io.getData();
    }

    ColorCommons::ColorCommons() {}

} // namespace lce::color
