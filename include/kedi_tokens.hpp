// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef KEDI_TOKENS_HPP
#define KEDI_TOKENS_HPP

#include <iostream>
#include <vector>

#include "kedi_tree.hpp"
#include "kedi_main.hpp"

enum KediTokens {
    KediGlobal    = '!',
    KediTree      = '[',
    KediTreeEnd   = ']',
    KediObject    = '=',
    KediObjectData='\'',

    KediUndefined = '?'
};

typedef struct {
public:
    std::vector<std::string> tokens;

    std::string last_line = "";
} kedi_keywords_t;

class Kedi_Tokenizer {
public:
    std::string last_key = "";

    kedi_keywords_t keys;

    void ltrim(std::string &data) {
        data.erase(data.begin(), std::find_if(data.begin(), data.end(),
                                              [](unsigned char ch) {
                                                  return !std::isspace(ch);
                                              }
        ));
    }

    kedi_keywords_t Tokenize(std::string data) noexcept {
        std::string append;
        std::vector<std::string> temporary_vector;

        ltrim(data);

        for(std::istringstream kedi_stream(data); kedi_stream >> append;){
            temporary_vector.push_back(append);
        }

        return kedi_keywords_t{temporary_vector, ""};
    }

    void MatchTokens(kedi_keywords_t &init, Kedi_Tree *&tree) noexcept {
        switch(init.tokens[0][0]) {
            case '=': {
                // Check first and last character of string
                if(init.tokens[1].front() != KediObjectData
                   || init.tokens.back()[init.tokens.size() - 1] == KediObjectData)
                    break;

                std::string data = "";

                if(1 >= init.tokens.size()) {
                    data.append(init.tokens[2]);
                }
                else {
                    for(int i = 1; i < init.tokens.size(); i++) {
                        data.append(init.tokens[i]);
                        data.append(1, ' ');
                    }
                }

                tree->InsertVar(last_key, init.tokens[0].erase(0, 1), data);

                break;
            }

            case '[': {
                last_key = init.tokens[0].erase(0, 1);

                tree->InsertCategory(last_key, {""});

                break;
            }
        }
    }
};


#endif // KEDI_TOKENS_HPP