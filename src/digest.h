#ifndef DIGEST_H
#define DIGEST_H

#include <vector>
#include <string>

class CDigest
{
public:
    typedef enum _DIGEST_TYPE
    {
        dtSHA256 = 0,
        dtSHA512,
        dtRIPEMD160
    } DIGEST_TYPE, *PDIGEST_TYPE;

public:
    CDigest();
    virtual ~CDigest();

    virtual void Update(
        const   void    *Data,
        const   size_t  DataSize) = 0;

    virtual void Finish(
        std::vector<unsigned char>  &DigestBuffer) = 0;

    static CDigest * CreateDigest(
        const   DIGEST_TYPE DigestType);
};

#endif // DIGEST_H
