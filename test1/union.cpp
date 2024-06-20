#include <stdio.h>

typedef union
{
    int i;
    float f;
    char str[20];
} Data;

typedef enum
{
    Tree,
    Bug
} Species;
typedef enum
{
    Big_tree,
    Acorn,
    Seedling
} Tree_forms;
typedef enum
{
    Caterpillar,
    Cocoon,
    Butterfly
} Bug_forms;
struct thing
{
    Species it;
    union
    {
        Tree_forms tree;
        Bug_forms bug;
    } form;
};

int main()
{
    Data data;
    data.i = 10;
    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    printf("data.str = %s\n", data.str);

    struct thing foo = {Tree, {Acorn}};
    printf("foo.it = %d\n", foo.it);
    printf("foo.form.tree = %d\n", foo.form.tree);
    return 0;
}