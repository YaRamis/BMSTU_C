#include "../inc/list.h"
#include "../inc/cars.h"

void append(node_t **head_a, node_t **head_b)
{
    if (*head_a == NULL)
        *head_a = *head_b;
    else if (*head_b == NULL)
        return;
    else
    {
        node_t *tmp = *head_a;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = *head_b;
    }

    *head_b = NULL;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    element->next = NULL;
    if (*head == NULL)
        *head = element;
    else
    {
        node_t *cur = *head;

        while (cur->next != NULL && comparator(cur->next->data, element->data) <= 0)
            cur = cur->next;

        if (cur == *head && comparator(cur->data, element->data) > 0)
        {
            element->next = cur;
            *head = element;
        }
        else
        {
            element->next = cur->next;
            cur->next = element;
        }
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *sorted = NULL;

    while (head != NULL)
    {
        node_t *element = head;
        head = head->next;
        sorted_insert(&sorted, element, comparator);
    }

    return sorted;
}

void *pop_back(node_t **head)
{
    void *data = NULL;

    if (head != NULL && *head != NULL)
    {
        node_t *cur = *head;
        node_t *prev = cur;

        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        
        data = cur->data;

        if (prev != cur)
        {
            free(cur);
            prev->next = NULL;
        }
        else
        {
            free(*head);
            *head = NULL;
        }
    }

    return data;
}

void *pop_front(node_t **head)
{
    void *data = NULL;

    if (head != NULL && *head != NULL)
    {
        data = (*head)->data;
        
        node_t *old_head = *head;
        data = old_head->data;
        (*head) = (*head)->next;

        free(old_head);
    }

    return data;
}

node_t *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

int push_list(node_t **head, void *data)
{
    node_t *new_node = create_node(data);
    if (new_node == NULL)
        return MEM_ALLOC_ERROR;
    
    new_node->next = *head;
    *head = new_node;
    return EXIT_SUCCESS;
}

void free_list(node_t *head)
{
    node_t *tmp = head;
    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

int push_cars_to_list(cars_t *cars, node_t **head)
{
    int rc;
    for (int i = 0; i < cars->size; i++)
    {
        rc = push_list(head, (void *)(&(cars->arr[i])));
        if (rc != EXIT_SUCCESS)
        {
            free_list(*head);
            return rc;
        }
    }
    return EXIT_SUCCESS;
}

void fwrite_list(node_t *head, FILE *f)
{
    char *str;
    while (head != NULL)
    {
        str = ((car_t *)(head->data))->brand;
        fprintf(f, "%s %d\n", str, ((car_t *)(head->data))->year);
        head = head->next;
    }
}
