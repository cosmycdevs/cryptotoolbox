#ifndef DIGEST_RIPEMD160_H
#define DIGEST_RIPEMD160_H

#include "digest.h"
#include "libs/bitcoin/crypto/ripemd160.h"

class CDigest_RIPEMD160:
        virtual public CDigest
{
private:
    CRIPEMD160  FHash;

public:
    CDigest_RIPEMD160();

    virtual void Update(
        const   void    *Data,
        const   size_t  DataSize);

    virtual void Finish(
        std::vector<unsigned char>  &DigestBuffer);
};

#endif // DIGEST_RIPEMD160_H
