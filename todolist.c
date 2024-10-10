#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LEN 100

void display_menu() {
    printf("\n--- To-Do List ---\n");
    printf("1. View tasks\n");
    printf("2. Add a task\n");
    printf("3. Mark a task as completed\n");
    printf("4. Delete a task\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void load_tasks(char tasks[MAX_TASKS][MAX_TASK_LEN], int *task_count) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        *task_count = 0; // No tasks yet
        return;
    }

    *task_count = 0;
    while (fgets(tasks[*task_count], MAX_TASK_LEN, file) != NULL) {
        tasks[*task_count][strcspn(tasks[*task_count], "\n")] = 0; // Remove newline
        (*task_count)++;
    }
    fclose(file);
}

void save_tasks(char tasks[MAX_TASKS][MAX_TASK_LEN], int task_count) {
    FILE *file = fopen("tasks.txt", "w");
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%s\n", tasks[i]);
    }
    fclose(file);
}

void view_tasks(char tasks[MAX_TASKS][MAX_TASK_LEN], int task_count) {
    if (task_count == 0) {
        printf("\nNo tasks found.\n");
        return;
    }
    printf("\nYour tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void add_task(char tasks[MAX_TASKS][MAX_TASK_LEN], int *task_count) {
    if (*task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter the new task: ");
    getchar();  // Clear input buffer
    fgets(tasks[*task_count], MAX_TASK_LEN, stdin);
    tasks[*task_count][strcspn(tasks[*task_count], "\n")] = 0; // Remove newline
    (*task_count)++;
    save_tasks(tasks, *task_count);
    printf("Task added successfully!\n");
}

void mark_task_completed(char tasks[MAX_TASKS][MAX_TASK_LEN], int *task_count) {
    if (*task_count == 0) {
        printf("\nNo tasks found.\n");
        return;
    }
    view_tasks(tasks, *task_count);
    printf("Enter the number of the task to mark as completed: ");
    int task_num;
    scanf("%d", &task_num);

    if (task_num < 1 || task_num > *task_count) {
        printf("Invalid task number!\n");
        return;
    }
    
    printf("Task '%s' marked as completed.\n", tasks[task_num - 1]);

    // Shift tasks up to remove completed task
    for (int i = task_num - 1; i < *task_count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    (*task_count)--;

    save_tasks(tasks, *task_count);
}

void delete_task(char tasks[MAX_TASKS][MAX_TASK_LEN], int *task_count) {
    if (*task_count == 0) {
        printf("\nNo tasks found.\n");
        return;
    }
    view_tasks(tasks, *task_count);
    printf("Enter the number of the task to delete: ");
    int task_num;
    scanf("%d", &task_num);

    if (task_num < 1 || task_num > *task_count) {
        printf("Invalid task number!\n");
        return;
    }

    printf("Task '%s' deleted.\n", tasks[task_num - 1]);

    // Shift tasks up to remove deleted task
    for (int i = task_num - 1; i < *task_count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    (*task_count)--;

    save_tasks(tasks, *task_count);
}

int main() {
    char tasks[MAX_TASKS][MAX_TASK_LEN];
    int task_count = 0;
    int choice;

    load_tasks(tasks, &task_count);

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_tasks(tasks, task_count);
                break;
            case 2:
                add_task(tasks, &task_count);
                break;
            case 3:
                mark_task_completed(tasks, &task_count);
                break;
            case 4:
                delete_task(tasks, &task_count);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option, try again.\n");
        }
    }

    return 0;
}
