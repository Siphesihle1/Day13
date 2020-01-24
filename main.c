/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smthethw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:36:09 by smthethw          #+#    #+#             */
/*   Updated: 2020/01/24 12:17:05 by smthethw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./ex00/ft_btree.h"
#include "./ex00/btree_create_node.c"
#include "./ex04/btree_insert_data.c"

//t_btree		*btree_create_node(void *item);

//void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));

/*void	insert(t_btree **root, void *item)
{
	if (!(*root))
	{	
		*root = btree_create_node(item);
		return ;
	}
	if (*(int*)item < *(int*)((*root)->item)) 
		insert(&(*root)->left, item);
	else
		insert(&(*root)->right, item);
}*/

void 	inorder(t_btree *root)
{
	if (!root) return ;
	inorder(root->left);
	printf("%i\n", *(int*)(root->item));
	inorder(root->right);
}

/*void	add_one(void *item)
{
	*(int*)item += 1;
}*/

int		comp(void *a, void *b)
{
	return (*(int*)a - *(int*)b);
}

int		main(void)
{
	int a = 1;
	int b = 2;
	int c = 3;

	int *ptr_a = &a;
	int *ptr_b = &b;
	int *ptr_c = &c;
	
	t_btree *root = NULL;
	btree_insert_data(&root, ptr_b, comp);
	btree_insert_data(&root, ptr_c, comp);
	btree_insert_data(&root, ptr_a, comp);
	//root->left = btree_create_node(ptr_a);
	//root->right = btree_create_node(ptr_c);
	//btree_apply_prefix(root, add_one);
	inorder(root);
	return (0);
}



