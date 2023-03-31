#include "../inc/matrix.h"

int input_matrix_to_list(matr_list_t **head, int *n, int *m)
{
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0)
        return MATRIX_SIZE_READ_ERROR;
    
    int elem;

    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
        {
            if (scanf("%d", &elem) != 1)
            {
                free_matrix_list(*head);
                return ELEM_READ_ERROR;
            }
            
            if (elem != 0)
                if (push_matrix_list(head, elem, i, j) == MEM_ALLOC_ERROR)
                {
                    free_matrix_list(*head);
                    return MEM_ALLOC_ERROR;
                }
        }
    
    if (*head == NULL)
        return EMPTY_MATRIX_LIST;

    return EXIT_SUCCESS;
}

void free_matrix_list(matr_list_t *head)
{
    matr_list_t *tmp = head;
    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

matr_list_t *create_matr_list_node(int data, int row, int col)
{
    matr_list_t *node = malloc(sizeof(matr_list_t));
    if (node != NULL)
    {
        node->col = col;
        node->data = data;
        node->next = NULL;
        node->row = row;
    }
    return node;
}

int push_matrix_list(matr_list_t **head, int data, int row, int col)
{
    matr_list_t *new_node = create_matr_list_node(data, row, col);
    if (new_node == NULL)
        return MEM_ALLOC_ERROR;
    
    if (*head == NULL)
        *head = new_node;
    else
    {
        matr_list_t *tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }

    return EXIT_SUCCESS;
}

int output_matrix_list(matr_list_t *head)
{
    if (head == NULL)
        return EMPTY_MATRIX_LIST;
    
    while (head != NULL)
    {
        printf("%d %d %d ", head->row, head->col, head->data);
        head = head->next;
    }
    return EXIT_SUCCESS;
}

matr_list_t *add_matrix_lists(matr_list_t *head_1, matr_list_t *head_2)
{
    matr_list_t *res = NULL;

    while (head_1 != NULL || head_2 != NULL)
    {
        if (head_1 == NULL)
        {
            if (push_matrix_list(&res, head_2->data, head_2->row, head_2->col) != EXIT_SUCCESS)
            {
                free_matrix_list(res);
                return NULL;
            }
            head_2 = head_2->next;
        }
        else if (head_2 == NULL)
        {
            if (push_matrix_list(&res, head_1->data, head_1->row, head_1->col) != EXIT_SUCCESS)
            {
                free_matrix_list(res);
                return NULL;
            }
            head_1 = head_1->next;
        }
        else
        {
            if (head_1->row > head_2->row)
            {
                if (push_matrix_list(&res, head_2->data, head_2->row, head_2->col) != EXIT_SUCCESS)
                {
                    free_matrix_list(res);
                    return NULL;
                }
                head_2 = head_2->next;
            }
            else if (head_1->row < head_2->row)
            {
                if (push_matrix_list(&res, head_1->data, head_1->row, head_1->col) != EXIT_SUCCESS)
                {
                    free_matrix_list(res);
                    return NULL;
                }
                head_1 = head_1->next;
            }
            else
            {
                if (head_1->col > head_2->col)
                {
                    if (push_matrix_list(&res, head_2->data, head_2->row, head_2->col) != EXIT_SUCCESS)
                    {
                        free_matrix_list(res);
                        return NULL;
                    }
                    head_2 = head_2->next;
                }
                else if (head_1->col < head_2->col)
                {
                    if (push_matrix_list(&res, head_1->data, head_1->row, head_1->col) != EXIT_SUCCESS)
                    {
                        free_matrix_list(res);
                        return NULL;
                    }
                    head_1 = head_1->next;
                }
                else
                {
                    if (head_1->data + head_2->data != 0)
                        if (push_matrix_list(&res, head_1->data + head_2->data, head_1->row, head_1->col) != EXIT_SUCCESS)
                        {
                            free_matrix_list(res);
                            return NULL;
                        }
                    head_1 = head_1->next;
                    head_2 = head_2->next;
                }
            }
        }
    }

    return res;
}

matr_list_t *mul_matrix_lists(matr_list_t *head_1, matr_list_t *head_2, int n, int m)
{
    matr_list_t *res = NULL;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (push_matrix_list(&res, 0, i, j) != EXIT_SUCCESS)
            {
                free_matrix_list(res);
                return NULL;
            }
    
    while (head_1 != NULL)
    {
        matr_list_t *tmp_2 = head_2;
        while (tmp_2 != NULL)
        {
            if (head_1->col == tmp_2->row)
            {
                matr_list_t *tmp_res = res;
                while (tmp_res->row != head_1->row || tmp_res->col != tmp_2->col)
                    tmp_res = tmp_res->next;
                tmp_res->data += head_1->data * tmp_2->data;
            }
            tmp_2 = tmp_2->next;
        }
        head_1 = head_1->next;
    }

    if (res != NULL)
    {
        matr_list_t *cur = res, *prev = NULL;
        while (cur != NULL)
        {
            if (cur->data == 0)
            {
                if (prev == NULL)
                {
                    res = cur->next;
                    free(cur);
                    cur = res;
                }
                else
                {
                    prev->next = cur->next;
                    free(cur);
                    cur = prev->next;
                }
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
    }

    return res;
}

int delete_max_element_matrix_list(matr_list_t **head)
{
    if (*head == NULL)
        return EMPTY_MATRIX_LIST;
    
    int max = (*head)->data, max_row = (*head)->row;
    matr_list_t *tmp = (*head)->next;

    while (tmp != NULL)
    {
        if (max < tmp->data)
        {
            max_row = tmp->row;
            max = tmp->data;
        }
        tmp = tmp->next;
    }

    matr_list_t *cur = *head, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->row == max_row)
        {
            if (prev == NULL)
            {
                (*head) = cur->next;
                free(cur);
                cur = *head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    cur = *head;
    while (cur != NULL)
    {
        if (cur->row > max_row)
            cur->row--;
        cur = cur->next;
    }

    if (*head == NULL)
        return EMPTY_MATRIX_LIST;

    return EXIT_SUCCESS;
}
