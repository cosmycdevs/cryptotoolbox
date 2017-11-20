#include "digest_sha256.h"

CDigest_SHA256::CDigest_SHA256()
{
};

void CDigest_SHA256::Update(
    const   void    *Data,
    const   size_t  DataSize)
{
    FHash.Write(
        reinterpret_cast<const unsigned char *>(Data),
        DataSize);
};

void CDigest_SHA256::Finish(
    std::vector<unsigned char>  &DigestBuffer)
{
    DigestBuffer.resize(CSHA256::OUTPUT_SIZE);
    FHash.Finalize(&DigestBuffer[0]);
};
