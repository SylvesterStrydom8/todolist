// ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void addTask(std::vector<std::string>& tasks);
void deleteTask(std::vector<std::string>& tasks);
void viewTasks(const std::vector<std::string>& tasks);
void saveTasks(const std::vector<std::string>& tasks, const std::string& filename);
void loadTasks(std::vector<std::string>& tasks, const std::string& filename);


int main()
{
	std::vector<std::string> tasks;
	std::string filename = "tasks.txt";
	int choice;

	loadTasks(tasks, filename);

	do
	{
		std::cout << "To-Do List Application" << std::endl;
		std::cout << "1. Add Task" << std::endl;
		std::cout << "2. Delete Task" << std::endl;
		std::cout << "3. View Tasks" << std::endl;
		std::cout << "4. Save Tasks" << std::endl;
		std::cout << "6. Exit" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			addTask(tasks);
			break;
		case 2:
			deleteTask(tasks);
			break;
		case 3:
			viewTasks(tasks);
			break;
		case 4:
			saveTasks(tasks, filename);
			break;
		case 6:
			std::cout << "Exiting application." << std::endl;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
		}

	} while (choice != 6);
}

void addTask(std::vector<std::string>& tasks) {
	std::string task;
	std::cout << "Enter the task: " << std::endl;
	std::cin.ignore();
	getline(std::cin, task);
	tasks.push_back(task);
	std::cout << "Task has been added." << std::endl;
}

void deleteTask(std::vector<::std::string>& tasks) {
	int index;
	viewTasks(tasks);
	std::cout << "Enter task number you want to delete: " << std::endl;
	std::cin >> index;
	if (index > 0 && index <= tasks.size())
	{
		tasks.erase(tasks.begin() + index - 1);
		std::cout << "Task deleted." << std::endl;
	}
	else {
		std::cout << "Invalid task number." << std::endl;
	}
}

void viewTasks(const std::vector<std::string>& tasks) {
	if (tasks.empty())
	{
		std::cout << "No tasks available" << std::endl;
	}
	else {
		std::cout << "Tasks:" << std::endl;
		for (int i = 0; i < tasks.size(); ++i)
		{	
			std::cout << i + 1 << ". " << tasks[i] << std::endl;
		}
	}
}

void saveTasks(const std::vector<std::string>& tasks, const std::string& filename) {
	std::ofstream outFile(filename);
	
	if (outFile.is_open())
	{
		for (const std::string& task : tasks)
		{
			outFile << task << std::endl;
		}
		outFile.close();
		std::cout << "Tasks saved to " << filename << "." << std::endl;
	} else {
		std::cout << "Error opening file for writing." << std::endl;
	}
}

void loadTasks(std::vector<std::string>& tasks, const std::string& filename) {
	std::ifstream inFile(filename);
	std::string task;

	if (inFile.is_open())
	{
		while (getline(inFile, task)) {
			tasks.push_back(task);
		}
		inFile.close();
		std::cout << "Tasks loaded from " << filename << std::endl;
	}
	else {
		std::cout << "Error opening file for reading." << std::endl;
	}
}