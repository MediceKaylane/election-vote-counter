#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define max 9

void count(int q, int n, string argv[]);

typedef struct
{
    string name;
    int vote;
}
election_count;

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: plurality [candidate...]\n");
        return 1;
    }

    int n = argc - 1, q;

    if (n > max)
    {
        printf("Maximum number of candidates is %i\n", max);
        return 1;
    }
    else
    {
        q = get_int("Number of votes: ");
        count(q, n, argv);
    }
}

void count(int q, int n, string argv[])
{
    int k = 0;
    election_count ec[max];

    for (int i = 0; i < n; i++)
    {
        ec[i].name = argv[i + 1];
        ec[i].vote = 0;
    }

    do
    {
        int e = 1;
        string name_1 = get_string("Vote: ");

        for (int j = 0; j < n; j++)
        {
            if (strcasecmp(ec[j].name, name_1) == 0)
            {
                ec[j].vote++;
                e = 0;
                k++;
                break;
            }
        }

        if (e == 1)
        {
            printf("Invalid name\n");
        }
    }
    while (k < q);

    int maior = ec[0].vote;

    for (int t = 1; t < n; t++)
    {
        if (ec[t].vote > maior)
        {
            maior = ec[t].vote;
        }
    }

    for (int l = 0; l < n; l++)
    {
        if (ec[l].vote == maior)
        {
            printf("%s\n", ec[l].name);
        }
    }
}
