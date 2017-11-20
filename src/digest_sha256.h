#ifndef DIGEST_SHA256_H
#define DIGEST_SHA256_H

#include "digest.h"
#include "libs/bitcoin/crypto/sha256.h"

class CDigest_SHA256:
        virtual public CDigest
{
private:
    CSHA256 FHash;

public:
    CDigest_SHA256();

    virtual void Update(
        const   void    *Data,
        const   size_t  DataSize);

    virtual void Finish(
        std::vector<unsigned char>  &DigestBuffer);
};

#endif // DIGEST_SHA256_H
