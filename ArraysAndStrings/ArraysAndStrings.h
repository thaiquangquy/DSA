#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ranges>

//>>>
namespace isUnique
{
    // 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
    // cannot use additional data structures?

    bool isUniqueWMap(std::string str)
    {
        bool isUnique = true;
        std::unordered_map<char, int> umap;
        for (size_t i = 0; i < str.length(); ++i)
        {
            // The insert and search time is O(1) in average
            // So the complexcity is O(n)

            // if (umap[str[i]] == 0)
            // {
            //     umap[str[i]] = 1;
            // }
            // else
            // {
            //     isUnique = false;
            //     break;
            // }

            if (umap.find(str[i]) == umap.end())
            {
                umap.insert(std::make_pair(str[i], 1));
            }
            else
            {
                isUnique = false;
                break;
            }
        }

        return isUnique;
    }

    // without a data struct this is a brutal force solution
    bool isUnique(std::string str)
    {
        bool isUnique = true;
        for (size_t i = 0; i < str.length(); ++i)
        {
            for (size_t j = i + 1; j < str.length(); ++j)
            {
                // call n-1, n-2,...,1 times
                if (str[i] == str[j])
                {
                    isUnique = false;
                    break;
                }
            }
        }
        // total time complexcity is O(n(n+1) / 2) ~ O(n^2)

        return isUnique;
    }

    // without a data struct this is an optimize solution
    bool isUniqueOp(std::string str)
    {
        // asume the character set is ASCII
        bool isUnique = true;
        const int char_set_size = 128; // total ASCII characters
        if (str.length() >= char_set_size)
        {
            return false;
        }
        bool char_set[char_set_size] = {false};
        for (size_t i = 0; i < str.length(); ++i)
        {
            int idx = (int)str[i];
            if (char_set[idx])
            {
                isUnique = false;
                break;
            }
            else
            {
                char_set[idx] = true;
            }
        }
        // total time complexcity is O(n) where n is string length

        return isUnique;
    }

    void isUniqueTest()
    {
        std::cout << "abcdefgh is unique: " << isUnique("abcdefgh") << std::endl;
        std::cout << "aabcdefgh is unique: " << isUnique("aabcdefgh") << std::endl;
        std::cout << "abbcdefgh is unique: " << isUnique("abbcdefgh") << std::endl;

        std::cout << "abcdefgh is unique wMap: " << isUniqueWMap("abcdefgh") << std::endl;
        std::cout << "aabcdefgh is unique wMap: " << isUniqueWMap("aabcdefgh") << std::endl;
        std::cout << "abVVbcdefgh is unique wMap: " << isUniqueWMap("abVVbcdefgh") << std::endl;

        std::cout << "abBcdefgh is unique op: " << isUniqueOp("abBcdefgh") << std::endl;
        std::cout << "aAbBcCdefgh is unique op: " << isUniqueOp("aAbBcCdefgh") << std::endl;
        std::cout << "aAbBcCcdefgh is unique op: " << isUniqueOp("aAbBcCcdefgh") << std::endl;
    }
    //<<<
} // namespace isUnique

//>>>
// 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
// A Permutation of a string is another string that contains same characters, only the order of characters can be different. For example, “abcd” and “dabc” are Permutation of each other.
namespace CheckPermutation
{
    // brutal force solution
    // Time complexity: O(nlog(n)) + O(nlog(n)) + n
    bool isPermutation(std::string first, std::string second)
    {
        if (first.length() != second.length())
        {
            return false;
        }
        std::sort(first.begin(), first.end());
        std::sort(second.begin(), second.end());

        for(size_t i = 0; i < first.length(); ++i)
        {
            if(first[i] != second[i])
            {
                return false;
            }
        }

        return true;
    }

    bool isPermutationExtend(std::string first, std::string second)
    {
        std::unordered_map<char, int> umap_first;
        std::unordered_map<char, int> umap_second;
        for (size_t i = 0; i < first.length(); ++i)
        {
            // The insert and search time is O(1) in average
            // So the complexcity is O(n)

            if (umap_first.find(first[i]) == umap_first.end())
            {
                umap_first.insert(std::make_pair(first[i], 1));
            }
            else
            {
                umap_first[first[i]]++;
            }

            if (umap_second.find(second[i]) == umap_second.end())
            {
                umap_second.insert(std::make_pair(second[i], 1));
            }
            else
            {
                umap_second[second[i]]++;
            }
        }

        for (size_t i = 0; i < first.length(); ++i)
        {
            if (umap_first[first[i]] != umap_second[first[i]])
            {
                return false;
            }
        }

        return true;
    }

    bool isPermutationArray(std::string first, std::string second)
    {
        std::vector<int> char_arr;
        std::unordered_map<char, int> umap_second;
        for (size_t i = 0; i < first.length(); ++i)
        {
            // The insert and search time is O(1) in average
            // So the complexcity is O(n)

            if (umap_first.find(first[i]) == umap_first.end())
            {
                umap_first.insert(std::make_pair(first[i], 1));
            }
            else
            {
                umap_first[first[i]]++;
            }

            if (umap_second.find(second[i]) == umap_second.end())
            {
                umap_second.insert(std::make_pair(second[i], 1));
            }
            else
            {
                umap_second[second[i]]++;
            }
        }

        for (size_t i = 0; i < first.length(); ++i)
        {
            if (umap_first[first[i]] != umap_second[first[i]])
            {
                return false;
            }
        }

        return true;
    }

    void isPermutationTest()
    {
        std::string first = "abba";
        std::string second = "abba";
        std::cout << "first: " << first << std::endl;
        std::cout << "second: " << second << std::endl;
        std::cout << "isPermutation: " << isPermutation(first, second) << std::endl;
        std::cout << "isPermutationExtend: " << isPermutationExtend(first, second) << std::endl;

        first = "abcd";
        second = "dcba";
        std::cout << "first: " << first << std::endl;
        std::cout << "second: " << second << std::endl;
        std::cout << "isPermutation: " << isPermutation(first, second) << std::endl;
        std::cout << "isPermutationExtend: " << isPermutationExtend(first, second) << std::endl;

        first = "aaaa";
        second = "bbbb";
        std::cout << "first: " << first << std::endl;
        std::cout << "second: " << second << std::endl;
        std::cout << "isPermutation: " << isPermutation(first, second) << std::endl;
        std::cout << "isPermutationExtend: " << isPermutationExtend(first, second) << std::endl;

        first = "aabbaaddbb";
        second = "bbaabbddaa";
        std::cout << "first: " << first << std::endl;
        std::cout << "second: " << second << std::endl;
        std::cout << "isPermutation: " << isPermutation(first, second) << std::endl;
        std::cout << "isPermutationExtend: " << isPermutationExtend(first, second) << std::endl;
    }
} // namespace name
//<<<