#include "digest_sha512.h"

CDigest_SHA512::CDigest_SHA512():
    CDigest()
{

};

void CDigest_SHA512::Update(
    const   void    *Data,
    const   size_t  DataSize)
{
    FHash.Write(
        reinterpret_cast<const unsigned char *>(Data),
        DataSize);
};

void CDigest_SHA512::Finish(
    std::vector<unsigned char>  &DigestBuffer)
{
    DigestBuffer.resize(CSHA512::OUTPUT_SIZE);
    FHash.Finalize(&DigestBuffer[0]);
};
