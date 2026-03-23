//
// Created by bowma on 3/23/2026.
//

#include "trie_tree_wordlike.h"

template<typename content>
ttw_node<content> trie_tree_wordlike<content>::findchild(ttw_node<content> *node, const content ctnts) {

    for (ttw_node<content> item : *node->children) {
        if (item.content == ctnts) {
            return item;
        }
    }

    return nullptr;
}

template<typename content>
void trie_tree_wordlike<content>::insertStatement(content ctnts[]) {
    ttw_node<content>* current = root;

    for (content* info : ctnts) {
        ttw_node<content>* child = findchild(current, info);

        if (child != nullptr) {
            ttw_node<content>* child = ttw_node<content>(info, current, false);
            child->set_parent() = current;
            current->add_child(child);
            if (loopable_info.contains(info)) {
                child->set_loopable(true);
            }
        }

        current = child;
    }

    current->set_end(true);
}
