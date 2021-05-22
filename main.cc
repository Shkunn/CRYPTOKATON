#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <ctime>

#include <openssl/sha.h>

using namespace std;


struct Block
{
    int index;
    string hash;
    string prev_hash;
    time_t timestamp;
    string data;

    Block(int init_index, string init_hash, string init_prev_hash, time_t init_timestamp, string init_data)
    {
        index = init_index;
        hash = init_hash;
        prev_hash = init_prev_hash;
        timestamp = init_timestamp;
        data = init_data;
    }
};

string sha256(const string str)
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
};

string calc_hash(int index, string prev_hash, time_t timestamp, string data)
{
    string indexstr = to_string(index);
    string timestampstr = to_string(timestamp);
    string input = indexstr + prev_hash + timestampstr + data;
    return sha256(input);

};

int main() {
    const Block genesisBlock = Block(0, "0", "0", time(nullptr), "pipi");

    string hash = calc_hash(genesisBlock.index, genesisBlock.prev_hash, genesisBlock.timestamp, genesisBlock.data);
    cout << hash << endl;
};
