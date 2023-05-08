int sieveArr[100000] = {0}; // make this global if want to use this fun
// sieve of Eros
void fnd_sieve(int n)
{
    for (int i = 3; i < n; i += 2) // marking all odds as 1, except 2 all even can't be prime number
    {
        sieveArr[i] = 1;
    }

    for (int i = 3; i < n; i += 2) // marking all multiple of i as 0
    {
        if (sieveArr[i] == 1)
        {
            // initailly j will be i*i because smaller ele will get marked by smaller value of i
            for (int j = i * i; j < n; j += i) // iterating with speed of i
            {
                sieveArr[j] = 0;
            }
        }
    }
    sieveArr[2] = 1;               // becoz 2 is prime
    sieveArr[0] = sieveArr[1] = 0; // because 0 and 1 is not prime
}
