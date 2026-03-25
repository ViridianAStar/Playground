//
// Created by bowma on 3/23/2026.
//

#include "automaton_like_trie.h"

#include <stdexcept>

template<typename content>
ttw_node<content> automaton_like_trie<content>::findchild(ttw_node<content> *node, const content ctnts) {

    for (ttw_node<content> item : *node->children) {
        if (item.content == ctnts) {
            return item;
        }
    }

    return nullptr;
}

template<typename content>
ttw_node<content> automaton_like_trie<content>::findloopable_child(ttw_node<content> *node, const content ctnts) {

    for (ttw_node<content> item : *node->loopable_children) {
        if (item.content == ctnts) {
            return item;
        }
    }

    return nullptr;
}

template<typename content>
void automaton_like_trie<content>::insertStatement(const std::vector<content>& ctnts) {
    ttw_node<content>* current = &root;

    for (content info : ctnts) {
        ttw_node<content> child = findchild(current, info);

        if (child != nullptr) {
            child = ttw_node<content>(info, current, false);
            child->set_parent() = current;
            current->add_child(child);
            if (loopable_info.contains(info)) {
                child->set_loopable(true);
                content back_reference = allowed_loops.at(info);
                ttw_node<content>* parent_traverse = child->get_parent();
                while (parent_traverse->contents != back_reference && parent_traverse->get_parent() != nullptr) {
                    parent_traverse = parent_traverse->get_parent();
                }
                if (parent_traverse->parent != nullptr) {
                    child->add_loopable_child(parent_traverse);
                } else {
                    throw std::out_of_range("Cannot find the top of this node loop");
                }
            }
        }

        current = child;
    }

    current->set_end(true);
}

template<typename content>
bool automaton_like_trie<content>::isValid(const std::vector<content>& ctnts) {
    ttw_node<content>* current = &root;
    for (content* info : ctnts) {
        ttw_node<content>* child = findchild(current, info);

        if (child == nullptr) {
            if (!current->get_loopable()) {
                return false;
            }
            child = current->get_loopable_child();
            if (child == nullptr) {
                return false;
            }
        }

        current = child;
    }

    return current->get_end();
}
