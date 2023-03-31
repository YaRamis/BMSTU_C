#include "../inc/matrix.h"

#define ACTION_STR_SIZE 100

int main(void)
{
    setbuf(stdout, NULL);

    char action[ACTION_STR_SIZE];

    if (scanf("%s", action) != 1)
        return ACTION_READ_ERROR;

    int rc;
    
    if (!strcmp(action, OUT))
    {
        matr_list_t *head = NULL;
        int n, m;
        rc = input_matrix_to_list(&head, &n, &m);
        if (rc != EXIT_SUCCESS)
            return rc;
        
        rc = output_matrix_list(head);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix_list(head);
            return rc;
        }
        free_matrix_list(head);
    }
    else if (!strcmp(action, ADD))
    {
        matr_list_t *head_1 = NULL;
        int n1, m1;
        rc = input_matrix_to_list(&head_1, &n1, &m1);
        if (rc != EXIT_SUCCESS)
            return rc;
        
        matr_list_t *head_2 = NULL;
        int n2, m2;
        rc = input_matrix_to_list(&head_2, &n2, &m2);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix_list(head_1);
            return rc;
        }
        
        matr_list_t *res = add_matrix_lists(head_1, head_2);
        if (res == NULL)
        {
            free_matrix_list(head_1);
            free_matrix_list(head_2);
            return MEM_ALLOC_ERROR;
        }

        rc = output_matrix_list(res);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix_list(head_1);
            free_matrix_list(head_2);
            free_matrix_list(res);
            return rc;
        }

        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
    }
    else if (!strcmp(action, MUL))
    {
        matr_list_t *head_1 = NULL;
        int n1, m1;
        rc = input_matrix_to_list(&head_1, &n1, &m1);
        if (rc != EXIT_SUCCESS)
            return rc;
        
        matr_list_t *head_2 = NULL;
        int n2, m2;
        rc = input_matrix_to_list(&head_2, &n2, &m2);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix_list(head_1);
            return rc;
        }
        
        matr_list_t *res = mul_matrix_lists(head_1, head_2, n1, m2);
        if (res == NULL)
        {
            free_matrix_list(head_1);
            free_matrix_list(head_2);
            return MEM_ALLOC_ERROR;
        }

        rc = output_matrix_list(res);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix_list(head_1);
            free_matrix_list(head_2);
            free_matrix_list(res);
            return rc;
        }

        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
    }
    else if (!strcmp(action, LIN))
    {
        matr_list_t *head = NULL;
        int n, m;
        rc = input_matrix_to_list(&head, &n, &m);
        if (rc != EXIT_SUCCESS)
            return rc;

        rc = delete_max_element_matrix_list(&head);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix_list(head);
            return rc;
        }
        
        rc = output_matrix_list(head);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix_list(head);
            return rc;
        }
        free_matrix_list(head);
    }
    else
        return WRONG_ACTION;

    return EXIT_SUCCESS;
}
