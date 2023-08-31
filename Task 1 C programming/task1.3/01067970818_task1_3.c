#include <stdio.h>
#include <stdlib.h>
/*
 * File: task1.part3
 * Author: Yara Mohamed
 * Description: C program that allows users to add, view, and
                remove tasks, each task has an id/index and a description. The id
                is a positive unique integer.
 * Date: 12/8/2023
 */
int taskCount = 0;
int taskIds[100];
char taskDescriptions[100][100];
//Functions Decleration
void add();
void view();
void removeTask();


int main() {
    int choice;

    printf("Minions Task Manager\n");
    do {
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
//Functions Definitions
    void add() {
        printf("Enter the description of the task: ");
        scanf(" %[^\n]", taskDescriptions[taskCount]);

        taskIds[taskCount] = taskCount + 1;
        taskCount += 1;
        printf("Task added successfully!\n");
    }

    void view() {
        if (taskCount == 0) {
            printf("No tasks found.\n");
            return;
        }

        printf("Current Tasks:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("Task ID: %d\nDescription: %s\n\n", taskIds[i], taskDescriptions[i]);
        }
    }

    void removeTask() {
        if (taskCount == 0) {
            printf("No tasks found.\n");
            return;
        }

        int taskId;
        printf("Enter task ID to remove: ");
        scanf("%d", &taskId);

        int taskIndex = -1;
        for (int i = 0; i < taskCount; i++) {
            if (taskIds[i] == taskId) {
                taskIndex = i;
                break;
            }
        }

        if (taskIndex != -1) {
            for (int i = taskIndex; i < taskCount - 1; i++) {
                taskIds[i] = taskIds[i + 1];
                strcpy(taskDescriptions[i], taskDescriptions[i + 1]);
            }
            taskCount--;
            printf("Task removed successfully!\n");
        } else {
            printf("Task not found.\n");
        }
    }

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                view();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                printf("Exiting Minions Task Manager. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
