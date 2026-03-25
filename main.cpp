#include "includes.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const std::vector<std::string> dictionary = {
        "a", "quick", "brown", "fox", "jumped", "over", "the", "turtle", "and", "dog"
    };

    const std::vector<std::string> statement1 = {
        "a", "quick", "brown", "fox"
    };

    const std::vector<std::string> statement2 = {
        "a", "quick", "brown", "fox", "jumped", "over", "the", "turtle", "over", "the", "turtle"
    };

    const std::vector<std::string> statement3 = {
        "a", "quick", "brown", "fox", "a", "quick", "brown", "fox", "jumped", "over", "the", "dog"
    };

    const std::vector<std::string> statement4 = {
        "a", "quick", "fox", "turtle", "over", "the", "turtle", "and", "the", "turtle"
    };

    const std::vector<std::string> extended1 = {
        "a", "quick", "brown", "fox",
        "a", "quick", "brown", "fox",
        "a", "quick", "brown", "fox"
    };

    auto structure = automaton_like_trie<std::string>();

    structure.loopable_info.emplace("fox", true);
    structure.allowed_loops.emplace("fox", "a");
    structure.loopable_info.emplace("turtle", true);
    structure.allowed_loops.emplace("turtle", "over");

    structure.insertStatement(dictionary);
    structure.insertStatement(statement1);
    structure.insertStatement(statement2);
    structure.insertStatement(statement3);
    structure.insertStatement(statement4);

    bool expected = true;
    bool actual = structure.isValid(dictionary);

    if (actual != expected) {
        printf("Incorrect output\n");
    } else {
        printf("PASS\n");
    }

    expected = false;
    const std::vector<std::string> ex = {"a"};
    actual = structure.isValid(ex);

    if (actual != expected) {
        printf("Incorrect output\n");
    } else {
        printf("PASS\n");
    }

    expected = true;
    actual = structure.isValid(statement1);

    if (actual != expected) {
        printf("Incorrect output\n");
    } else {
        printf("PASS\n");
    }

    actual = structure.isValid(extended1);

    if (actual != expected) {
        printf("Incorrect output\n");
    } else {
        printf("PASS\n");
    }
}