
#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long i, y, e;
    long long p, q, r, t;

    cout << "============================================\n";
    cout << "   CAMPAIGN AUDIENCE DEDUPLICATION SYSTEM\n";
    cout << "============================================\n";

    cout << "\nEnter the individual audience counts:\n";

    cout << "Instagram audience: ";
    cin >> i;

    cout << "YouTube audience: ";
    cin >> y;

    cout << "Email audience: ";
    cin >> e;

    cout << "\nEnter the pairwise overlap counts:\n";

    cout << "Instagram and YouTube: ";
    cin >> p;

    cout << "Instagram and Email: ";
    cin >> q;

    cout << "YouTube and Email: ";
    cin >> r;

    cout << "\nEnter the audience common to all three channels: ";
    cin >> t;

    // Check whether input was entered correctly.
    if (cin.fail())
    {
        cout << "\nError: Please enter valid integer values.\n";
        return 1;
    }

    // All audience counts must be non-negative.
    if (i < 0 || y < 0 || e < 0 ||
        p < 0 || q < 0 || r < 0 || t < 0)
    {
        cout << "\nError: Audience counts cannot be negative.\n";
        return 1;
    }

    // Validate pairwise overlaps.
    if (p > i || p > y ||
        q > i || q > e ||
        r > y || r > e)
    {
        cout << "\nError: A pairwise overlap cannot exceed "
             << "either individual audience.\n";
        return 1;
    }

    // The three-way overlap must belong to every pairwise overlap.
    if (t > p || t > q || t > r)
    {
        cout << "\nError: The three-way overlap cannot exceed "
             << "any pairwise overlap.\n";
        return 1;
    }

    // Validate the seven individual regions of the Venn diagram.
    long long iOnly = i - p - q + t;
    long long yOnly = y - p - r + t;
    long long eOnly = e - q - r + t;

    long long iyOnly = p - t;
    long long ieOnly = q - t;
    long long yeOnly = r - t;

    if (iOnly < 0 || yOnly < 0 || eOnly < 0 ||
        iyOnly < 0 || ieOnly < 0 || yeOnly < 0)
    {
        cout << "\nError: The overlap data is inconsistent.\n";
        cout << "Please check the audience counts and overlaps.\n";
        return 1;
    }

    // Principle of Inclusion-Exclusion.
    long long uniqueReach =
        i + y + e - p - q - r + t;

    // Calculate the exact audience categories.
    long long exactlyOne = iOnly + yOnly + eOnly;
    long long exactlyTwo = iyOnly + ieOnly + yeOnly;
    long long exactlyThree = t;

    // Verify the calculated result.
    long long totalCategories =
        exactlyOne + exactlyTwo + exactlyThree;

    cout << "\n============================================\n";
    cout << "             CALCULATION RESULTS\n";
    cout << "============================================\n";

    cout << "\n1. Individual Audience Counts\n";
    cout << "Instagram : " << i << '\n';
    cout << "YouTube   : " << y << '\n';
    cout << "Email     : " << e << '\n';

    cout << "\n2. Audience Overlaps\n";
    cout << "Instagram and YouTube : " << p << '\n';
    cout << "Instagram and Email   : " << q << '\n';
    cout << "YouTube and Email     : " << r << '\n';
    cout << "All three channels    : " << t << '\n';

    cout << "\n3. Audience by Exact Category\n";
    cout << "Instagram only        : " << iOnly << '\n';
    cout << "YouTube only          : " << yOnly << '\n';
    cout << "Email only            : " << eOnly << '\n';
    cout << "Instagram + YouTube only : "
         << iyOnly << '\n';
    cout << "Instagram + Email only   : "
         << ieOnly << '\n';
    cout << "YouTube + Email only     : "
         << yeOnly << '\n';

    cout << "\n4. Final Results\n";
    cout << "Exactly one channel : " << exactlyOne << '\n';
    cout << "Exactly two channels: " << exactlyTwo << '\n';
    cout << "All three channels  : " << exactlyThree << '\n';

    cout << "\n--------------------------------------------\n";
    cout << "TOTAL UNIQUE REACH  : " << uniqueReach << '\n';
    cout << "--------------------------------------------\n";

    cout << "\n5. Verification\n";
    cout << "N1 + N2 + N3 = "
         << exactlyOne << " + "
         << exactlyTwo << " + "
         << exactlyThree << '\n';

    cout << "Sum of categories = " << totalCategories << '\n';
    cout << "Unique reach      = " << uniqueReach << '\n';

    if (totalCategories == uniqueReach)
    {
        cout << "Verification successful!\n";
        cout << "All categories add up to unique reach.\n";
    }
    else
    {
        cout << "Verification failed. Check the input data.\n";
    }

    cout << "\n============================================\n";
    cout << "              PROGRAM ENDED\n";
    cout << "============================================\n";

    return 0;
}
