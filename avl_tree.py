def search(tree: binary_node, value: int):
    if tree is None:
        return False
    if tree.value == value:
        return True
    if value < tree.value:
        return search(tree.left, value)
    else:
        return search(tree.right, value)

    
def insert(tree: binary_node, new_node:binary_node):

    tree_node = tree
    parent_node = None
    if tree_node == None:
        tree_node = new_node

    while tree_node != None:
        if new_node.value < tree_node.value:
            parent_node = tree_node
            tree_node = tree_node.left
        else:
            parent_node = tree_node
            tree_node = tree_node.right

    if new_node.value < parent_node.value:
        parent_node.add_l(new_node)
    else:
        parent_node.add_r(new_node)

def minimum(tree:binary_node):
    a = None
    node = tree
    while node != None:
        a = node
        node = node.left
    return a

def maximum(tree:binary_node):
    a = None
    node = tree
    while node != None:
        a = node
        node = node.right
    return a

def predecessor(node:binary_node):
    if node.left != None:
        return maximum(node.left)
    y = node.parent
    while y != None and y.left == node:
        x = y 
        y = x.parent
    return y

def sucessor(node:binary_node):
    if node.right != None:
        return minimum(node.right)
    y = node.parent
    while y != None and y.right == node:
        x = y
        y = x.parent
    return y

def delete(node:binary_node):
        #caso1
    if node.left == None and node.right == None:
        if node.parent is None:
            return None
        if node.parent.left == node:
            node.parent.left = None
        else:
            node.parent.right = None
        #caso2 
    elif node.left == None or node.right == None:
        child = node.left if node.left else node.right
        if node.parent is None:
            child.parent = None
            return child
        if node.parent.left == node:
            node.parent.left = child
        else:
            node.parent.right = child
        child.parent = node.parent

    #caso3 
    else:
        succ = minimum(node.right)
        node.value = succ.value
        delete(succ)




class binary_node:
    def __init__(self, value, parent = None):
        self.parent = parent
        self.value = value
        self.left= None
        self.right= None

    def add_l(self, node):
        self.left = node
        self.left.parent = self
        

    def add_r(self, node):
        self.right = node
        self.right.parent = self
    

if __name__ == "__main__":
    pnode = binary_node(10)
    rightnode = binary_node(15)
    leftnode = binary_node(3)
    
    pnode.add_r(rightnode)
    pnode.add_l(leftnode)
    
    nodell = binary_node(2)
    nodelr = binary_node(5)

    noderr = binary_node(18)
    noderl = binary_node(11)

    pnode.left.add_l(nodell)
    pnode.left.add_r(nodelr)

    pnode.right.add_l(noderl)
    pnode.right.add_r(noderr)
    
    new_node = binary_node(40)

    print(f"pnode: {hex(id(pnode))}\nleafnode: {hex(id(noderr.parent.parent))}")
    print(search(pnode, 5))
    insert(pnode, new_node)
    print(f"new_node_p: {new_node.parent.value}")
    print(f"maximum: {maximum(pnode).value}\tminimum: {minimum(pnode).value}")
    print(f"sucessor: {sucessor(noderr).value}\t predecessor: {predecessor(noderr).value if predecessor(noderr) != None else predecessor(noderr)}")
    print(f"Del: {delete(pnode)}\t{rightnode.parent}")
