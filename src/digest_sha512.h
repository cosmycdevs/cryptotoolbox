#ifndef DIGEST_SHA512_H
#define DIGEST_SHA512_H

#include "digest.h"
#include "libs/bitcoin/crypto/sha512.h"

class CDigest_SHA512:
        virtual public CDigest
{
private:
    CSHA512 FHash;

public:
    CDigest_SHA512();

    virtual void Update(
        const   void    *Data,
        const   size_t  DataSize);

    virtual void Finish(
        std::vector<unsigned char>  &DigestBuffer);
};


#endif // DIGEST_SHA512_H
