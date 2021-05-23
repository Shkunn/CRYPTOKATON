#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <transaction.h>

#define PUBKEY_HEADER "-----BEGIN PUBLIC KEY-----"
#define PUBKEY_FOOTER "-----END PUBLIC KEY-----"

using namespace std;

namespace BeerCoin {

	bool check_signature(SignedMessage* msg) {
		RSA* public_key_;
		BIO* bo = BIO_new(BIO_s_mem());
		BIO_write(bo, (PUBKEY_HEADER + msg->publicKey + PUBKEY_FOOTER).c_str(), msg->publicKey.length());

		PEM_read_bio_RSA_PUBKEY(bo, &public_key_, 0, 0);
		int result = RSA_verify(
			NID_RSA_SHA3_256,
			(const unsigned char*) msg->message.c_str(), 
			msg->message.length(),
			(const unsigned char*) msg->signature.c_str(),
			msg->signature.length(), public_key_
		);
		BIO_free(bo);
		RSA_free(public_key_);
		return result == 1;
	}

	string sha256(string str)
	{
			unsigned char hash[SHA256_DIGEST_LENGTH];
			SHA256_CTX sha256;
			SHA256_Init(&sha256);
			SHA256_Update(&sha256, str.c_str(), str.size());
			SHA256_Final(hash, &sha256);
			stringstream ss;

			for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			{
				ss << hex << setw(2) << setfill('0') << (int)hash[i];
			}
			return ss.str();
	}

}

