#include "digest_ripemd160.h"

CDigest_RIPEMD160::CDigest_RIPEMD160():
    CDigest()
{
};

void CDigest_RIPEMD160::Update(
    const   void    *Data,
    const   size_t  DataSize)
{
    FHash.Write(
        reinterpret_cast<const unsigned char *>(Data),
        DataSize);
};

void CDigest_RIPEMD160::Finish(
    std::vector<unsigned char>  &DigestBuffer)
{
    DigestBuffer.resize(CRIPEMD160::OUTPUT_SIZE);
    FHash.Finalize(&DigestBuffer[0]);
};
