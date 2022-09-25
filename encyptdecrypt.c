#include<stdio.h>
#include <stdlib.h>
#include<strings.h>
#include<time.h>

void encrypt(char c1[1000000])
{
    int key;
    srand(time(NULL));
    key = rand() % (126-32);
    for(int i=0; i<(strlen(c1)); i++)
    {
        c1[i] -= 32;
        c1[i]= 32 + (c1[i] + key)%(126-32);
    }
    printf("The ciphertext is \n%s\n", c1);
    printf("The key is \n%d", key);
}

void decrypt(char c2[1000000], int key)
{
    key = (126-32) - key;
    srand(time(NULL));
    for(int i=0; i<(strlen(c2)); i++)
    {
        c2[i] -= 32;
        c2[i]= 32 + (c2[i] + key)%(126-32);
    }
    printf("The plaintext is \n%s", c2);
}

int main()
{
    int x;
    printf("Press 1 to encrypt a message\n");
    printf("Press 2 to decrypt a message\n");
    scanf("%d", &x);
    if(x==1)
    {
        char c[1000000];
        printf("Encryption:\nEnter the plaintext\n");
        
        scanf("\n");
        scanf("%[^\n]s", c);
        encrypt(c);
    }
    if(x==2)
    {
        char c[1000000];
        printf("Decryption:\nEnter the ciphertext\n");
        scanf("\n");
        scanf("%[^\n]s", c);
        int key;
        printf("Enter the key\n");
        scanf("%d",&key);
        decrypt(c, key);

    }
    return 0;
}