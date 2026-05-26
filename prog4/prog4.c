struct Bitfield
{
    unsigned int firstbit : 1;
    unsigned int secondbit : 1;
    unsigned int value : 4;
};

int main()
{
    struct Bitfield a;

    a.firstbit = 1;
    a.secondbit = 0;
    a.value = 10;

    printf("%u\n", a.firstbit);
    printf("%u\n", a.secondbit);
    printf("%u\n", a.value);

    return 0;
}