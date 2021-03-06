/**
 * \file   Test_Blowfish.cpp
 * \brief
 */


#include <xLib/xLib.h>

//-------------------------------------------------------------------------------------------------
using namespace xl;

xTEST_CLASS(Test_Blowfish)
xTEST_UNIT(Test_Blowfish)
//-------------------------------------------------------------------------------------------------
/* virtual */
bool_t
Test_Blowfish::unit()
{
#if cmOPENSSL_CRYPTO_FOUND

    xTEST_CASE("encryptCfb64")
    {
        std::ustring_t plain[] = {
            std::ustring_t(1,  'a'),
            std::ustring_t(2,  'b'),
            std::ustring_t(3,  'c'),
            std::ustring_t(8,  'd'),
            std::ustring_t(11, 'e'),
            std::ustring_t(12, 'f'),
            std::ustring_t(16, 'j'),
            std::ustring_t(17, 'h'),
            std::ustring_t(28, 'i'),
            std::ustring_t(32, 'j'),
            std::ustring_t(51, 'k')
        };

        for (size_t i = 0; i < xARRAY_SIZE(plain); i ++) {
            Blowfish blowfish;
            std::tstring_t key = xT("8888r88888");
            std::ustring_t encrypted;
            std::ustring_t decrypted;

            blowfish.setKey(key);
            blowfish.encryptCfb64(plain[i], &encrypted, Blowfish::CryptMode::cmEncrypt);
            blowfish.encryptCfb64(encrypted, &decrypted, Blowfish::CryptMode::cmDecrypt);

            xTEST_EQ(plain[i], decrypted);
            xTEST_EQ(Crc32().calc(&(plain[i]).at(0), plain[i].size()),
                Crc32().calc(&decrypted.at(0), decrypted.size()));
        }
    }

    xTEST_CASE("encryptFileCfb64")
    {
        Blowfish blowfish;
        std::tstring_t key           = xT("888888888A");
        std::tstring_t filePlain     = data.tempDirPath + Const::slash() + xT("Blowfish.txt");
        std::tstring_t fileEncrypted = data.tempDirPath + Const::slash() + xT("Blowfish_Encrypted.txt");
        std::tstring_t fileDecrypted = data.tempDirPath + Const::slash() + xT("Blowfish_Decrypted.txt");

        // prepare
        {
            File::textWrite(filePlain, xT("text_text"), File::OpenMode::omWrite);
        }

        // test
        blowfish.setKey(key);
        blowfish.encryptFileCfb64(filePlain, fileEncrypted, Blowfish::CryptMode::cmEncrypt);
        blowfish.encryptFileCfb64(fileEncrypted, fileDecrypted, Blowfish::CryptMode::cmDecrypt);

        {
            File fileIn;
            fileIn.create(filePlain, File::OpenMode::omBinRead);

            File fileOut;
            fileOut.create(fileDecrypted, File::OpenMode::omBinRead);

            xTEST_EQ(fileIn.size(), fileOut.size());
            xTEST_EQ(Crc32().calcFile(filePlain), Crc32().calcFile(fileDecrypted));
        }
    }

#endif // cmOPENSSL_CRYPTO_FOUND

    return true;
}
//-------------------------------------------------------------------------------------------------

