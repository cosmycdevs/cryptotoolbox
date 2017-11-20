#include "digest.h"
#include "digest_sha256.h"
#include "digest_sha512.h"
#include "digest_ripemd160.h"

CDigest::CDigest()
{
};

CDigest::~CDigest()
{
};

CDigest * CDigest::CreateDigest(
    const   DIGEST_TYPE DigestType)
{
    switch (DigestType)
    {
    case dtSHA256:
        {
            return new CDigest_SHA256();
        }break;

    case dtSHA512:
        {
            return new CDigest_SHA512();
        }break;

    case dtRIPEMD160:
        {
            return new CDigest_RIPEMD160();
        }break;
    };

    return nullptr;
};
