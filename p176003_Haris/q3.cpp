// T(n) = O(n^2)


compute-lps(s, n):

    // palindromes with length 1
    for i = 1 to n:
        c[i, i] = 1
    // palindromes with length up to 2
    for i = 1 to n-1:
        c[i, i+1] = (s[i] == s[i+1]) ? 2 : 1

    // palindromes with length up to j+1
    for j = 2 to n-1:
        for i = 1 to n-i:
            if s[i] == s[i+j]:
                c[i, i+j] = 2 + c[i+1, i+j-1]
            else:
                c[i, i+j] = max( c[i+1, i+j] , c[i, i+j-1] )