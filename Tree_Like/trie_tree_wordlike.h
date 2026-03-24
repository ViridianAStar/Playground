//
// Created by bowma on 3/23/2026.
//

#ifndef PLAYGROUND_TRIE_TREE_WORDLIKE_H
#define PLAYGROUND_TRIE_TREE_WORDLIKE_H
#include <unordered_map>
#include <vector>


/**
 * It's like a trie or a tree but for "words" and nodes can loop back on themselves potentially infinitely
 * Granted for a node to loop infinitely it would require infinite space*
 */
template<typename content>
class ttw_node {
    ttw_node* parent;
    bool loopable = false;
    bool end;
public:
    content contents;
    std::pmr::vector<ttw_node*> children;
    std::pmr::vector<ttw_node*> loopable_children;
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

    void set_end(const bool ends) {end = ends;}
    [[nodiscard]] bool get_end() const {return end;}

    /**
     * If for some reason you must move a node to a different part of the structure you can set its parent elsewhere
     *
     * @param parent
     */
    void set_parent(ttw_node* parent) {this->parent = parent;}

    void get_parent(ttw_node* parent) {this->parent = parent;}

    /**
     * Add children so you can build the data structure. Useful if you extend it on the fly.
     *
     * @param child
     */
    void add_child(ttw_node* child) {children.push_back(child);}

    /**
     * Remove children useful if allowable statements change
     *
     * @param child
     */
    void remove_child(ttw_node* child) {children.remove(child);}

    void add_loopable_child(ttw_node* child) {loopable_children.push_back(child);}

    void remove_loopable_child(ttw_node* child) {loopable_children.remove(child);}

    /**
     * Build a node
     *
     * @param ctnts
     * @param parent
     * @param ends
     */
    ttw_node(content ctnts, ttw_node* parent, const bool ends) : parent(parent), end(ends), contents(ctnts) {}
};

template<typename content>
class trie_tree_wordlike {
    // value -10 integer by default can contain other types as children
    ttw_node<int> root = ttw_node<int>(-10, nullptr, false);

    ttw_node<content> findchild(ttw_node<content>* node, const content ctnts);
    ttw_node<content> findloopable_child(ttw_node<content>* node, const content ctnts);

    // last to first
    std::pmr::unordered_map<content, content> allowed_loops;

    std::pmr::unordered_map<content, bool> loopable_info;
    public:
        void insertStatement(content ctnts[]);
        bool isValid(content ctnts[]);
};


#endif //PLAYGROUND_TRIE_TREE_WORDLIKE_H