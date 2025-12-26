#include "VhashMap.h"

char *strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    if (copy != NULL) {
        memcpy(copy, s, len);
    }
    return copy;
}

int finalMix64(uint64_t key){ // Fonction finale de mélange de bits

    uint64_t k = key;
    uint64_t magicNumber1 = 0xff51afd7ed558ccd;
    uint64_t magicNumber2 = 0xc4ceb9fe1a85ec53;


    k = k ^ (k >> 33); // décalage de 33 bits vers la droite sur k XOR avec k
    k = k * magicNumber1;
    k = k ^ (k >> 33);
    k = k * magicNumber2;
    k = k ^ (k >> 33);

    return k;
}
uint64_t MurmurHash64(char *key, uint64_t seed) {
    const uint64_t m = 0xc6a4a7935bd1e995;
    const int r = 47;
    uint64_t h = seed ^ (strlen(key) * m);
    const uint64_t *data = (const uint64_t *)key;
    const uint64_t *end = data + (strlen(key) / 8);

    while (data != end) {
        uint64_t k = *data++;
        k *= m;
        k ^= k >> r;
        k *= m;
        h ^= k;
        h *= m;
    }

    const unsigned char *data2 = (const unsigned char *)data;
    switch (strlen(key) & 7) {
        case 7: h ^= (uint64_t)data2[6] << 48;
        case 6: h ^= (uint64_t)data2[5] << 40;
        case 5: h ^= (uint64_t)data2[4] << 32;
        case 4: h ^= (uint64_t)data2[3] << 24;
        case 3: h ^= (uint64_t)data2[2] << 16;
        case 2: h ^= (uint64_t)data2[1] << 8;
        case 1: h ^= (uint64_t)data2[0];
            h *= m;
    };

    h ^= h >> r;
    h *= m;
    h ^= h >> r;
    return h;
}

t_HashMap * HM_Create(int size){

    t_HashMap * res;
    res->slots = malloc(sizeof(t_HashMap_Element) * size);
    memset(res->slots, 0, sizeof(t_HashMap_Element) * size);

    res->seed = (time(NULL));

    printf("%d", res->seed);







}

int main(){
    
    t_HashMap * hm = HM_Create(10);   


}