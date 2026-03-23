//
// Created by bowma on 3/23/2026.
//

#ifndef PLAYGROUND_TRIE_TREE_WORDLIKE_H
#define PLAYGROUND_TRIE_TREE_WORDLIKE_H
#include <vector>


/**
 * It's like a trie or a tree but for "words" and nodes can loop back on themselves potentially infinitely
 * Granted for a node to loop infinitely it would require infinite space*
 */
template<typename content>
class ttw_node {
private:
    content contents;
    ttw_node* parent;
    bool loopable = false;
    std::pmr::vector<ttw_node*> children;
    bool end;
public:
    /**
     *
     * @param lpbl boolean value to set for loopable
     */
    void set_loopable(const bool lpbl) {loopable = lpbl;}

    /**
     * Tells you if a node can loop
     * @return
     */
    [[nodiscard]] bool get_loopable() const {return loopable;}

    /**
     * If for some reason you must move a node to a different part of the structure you can set its parent elsewhere
     *
     * @param parent
     */
    void set_parent(ttw_node<content>* parent) {this->parent = parent;}

    /**
     * Add children so you can build the data structure. Useful if you extend it on the fly.
     *
     * @param child
     */
    void add_child(ttw_node<content>* child) {children.push_back(child);}

    /**
     * Remove children useful if allowable statements change
     *
     * @param child
     */
    void remove_child(ttw_node<content>* child) {children.remove(child);}

    /**
     * Build a node
     *
     * @param ctnts
     * @param parent
     * @param ends
     */
    ttw_node(content ctnts, ttw_node* parent, const bool ends) : contents(ctnts), parent(parent), end(ends) {}
};

class trie_tree_wordlike {

};


#endif //PLAYGROUND_TRIE_TREE_WORDLIKE_H