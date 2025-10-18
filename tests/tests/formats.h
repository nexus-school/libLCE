//
// Created by DexrnZacAttack on 9/3/25 using zPc-i2.
//
#pragma once
#include "LCE/color/ColorFile.h"
#include "util.h"
#include <BinaryIO/BinaryIO.h>

namespace lce {
    namespace io {
        enum class ByteOrder;
    }

    namespace color {
        class ColorFile;
    }

    namespace tests::formats {
        // Saves
        void saveFromFolderTest();
        void saveTestEndian(bio::ByteOrder endian);
        void saveTestVita();
        void saveTestSwitch(bio::ByteOrder endian);
        void oldSaveTest();
        // World
        // void regionTest();
        void compressedChunkTest();
        // File formats
        void arcTest();
        void locTest();
        void msscmpTest(bio::ByteOrder endian);
        void colorWriteTest(const color::ColorFileCommons &colors);
        void colorTest();
        void thumbTest(bio::ByteOrder endian, int headerSize,
                       bool use4Byte = false);

        inline void run() {
            ADD_TEST(SAVEGAME_FROM_FOLDER,
                     lce::tests::formats::saveFromFolderTest,
                     util::types::FORMATS, "Create savegame from folder");
            ADD_TEST(BE_SAVEGAME, lce::tests::formats::saveTestEndian,
                     util::types::FORMATS,
                     "Read & Write Big Endian savegame.dat",
                     bio::ByteOrder::BIG);
            ADD_TEST(LE_SAVEGAME, lce::tests::formats::saveTestEndian,
                     util::types::FORMATS,
                     "Read & Write Little Endian savegame.dat",
                     bio::ByteOrder::LITTLE);
            ADD_TEST(BE_TO_LE_SAVEGAME, lce::tests::formats::saveTestSwitch,
                     util::types::FORMATS,
                     "Switch Big Endian to Little Endian savegame.dat",
                     bio::ByteOrder::LITTLE);
            ADD_TEST(LE_TO_BE_SAVEGAME, lce::tests::formats::saveTestSwitch,
                     util::types::FORMATS,
                     "Switch Little Endian to Big Endian savegame.dat",
                     bio::ByteOrder::BIG);
            ADD_TEST(PRERELEASE_SAVEGAME, lce::tests::formats::oldSaveTest,
                     util::types::FORMATS, "Read & Write PR savegame.dat");
            ADD_TEST(PSVITA_SAVEGAME, lce::tests::formats::saveTestVita,
                     util::types::FORMATS, "Read & Write PSVita savegame.dat");
            ADD_TEST(ARC, lce::tests::formats::arcTest, util::types::FORMATS,
                     "Read example.arc");
            ADD_TEST(LOC, lce::tests::formats::locTest, util::types::FORMATS,
                     "Read example.loc");
            ADD_TEST(COL, lce::tests::formats::colorTest, util::types::FORMATS,
                     "Read COL file");
            ADD_TEST(BE_THUMB, lce::tests::formats::thumbTest,
                     util::types::FORMATS, "Read Big Endian THUMB",
                     bio::ByteOrder::BIG, 0x100, false);
            ADD_TEST(LE_THUMB, lce::tests::formats::thumbTest,
                     util::types::FORMATS, "Read Little Endian THUMB",
                     bio::ByteOrder::LITTLE, 0x100, false);
            ADD_TEST(SWITCH_4B_WCHAR_THUMB, lce::tests::formats::thumbTest,
                     util::types::FORMATS, "Read Switch THUMB",
                     bio::ByteOrder::LITTLE, 0x208, true);
            ADD_TEST(READ_COMPRESSED_CHUNK,
                     lce::tests::formats::compressedChunkTest,
                     util::types::FORMATS, "Read compressed chunk");
            // ADD_TEST(READ_REGION, lce::tests::formats::regionTest,
            //          util::types::FORMATS, "Read region");
            ADD_TEST(NEWGEN_MSSCMP, lce::tests::formats::msscmpTest,
                     util::types::FORMATS, "Read newgen MSSCMP",
                     bio::ByteOrder::LITTLE);
            ADD_TEST(OLDGENMSSCMP, lce::tests::formats::msscmpTest,
                     util::types::FORMATS, "Read oldgen MSSCMP",
                     bio::ByteOrder::BIG);
        }
    } // namespace tests::formats
} // namespace lce
