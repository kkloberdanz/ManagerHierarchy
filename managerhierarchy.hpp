#ifndef MANAGERHIERARCHY_HPP
#define MANAGERHIERARCHY_HPP

#include <iostream>
#include <vector>

class ManagerHierarchy {
    private:
        std::string                     name;
        std::vector<ManagerHierarchy*>  employees; 
        ManagerHierarchy                *manager;

    public:
        ManagerHierarchy () {
            this->manager = NULL;
        }

        ~ManagerHierarchy() {
            for (auto empl : this->employees) {
                delete empl;
            }
        } 

        void clear() {
            for (auto empl : this->employees) {
                delete empl;
            }
            this->employees.clear();
        }

        void insert(std::string manager, std::string employee) { 
            ManagerHierarchy *found = this->find(manager);
            if (found != NULL) {

            } else {
                //std::cout << "Creating CEO: " << manager << std::endl;
                this->name = manager;
                found = this;
            }
            ManagerHierarchy *m = new ManagerHierarchy;
            m->manager = found;
            m->name    = employee;
            found->employees.push_back(m);
            //std::cout << "Successfully inserted: " << m->name << std::endl;
        }

        ManagerHierarchy* find(std::string employee) {
            
            if (this == NULL) {
                std::cout << "Reached NULL" << std::endl;
                return NULL;
            }

            ManagerHierarchy *found;

            if (this->name == employee) {
                return this;
            } else if (!this->employees.empty()) {
                for (const auto& empl : this->employees) {
                    found = empl->find(employee);
                    if (found != NULL) { 
                        return found;
                    }
                }
            }
            return NULL;
        }
        
        std::vector<ManagerHierarchy*> get_all_supervisors(std::string employee) {
            ManagerHierarchy *found = this->find(employee); 

            std::vector<ManagerHierarchy*> visited;

            while (found != NULL) {
                found = found->manager;
                if (found != NULL) {
                    visited.push_back(found);
                } else {
                    break;
                } 
            }
            return visited;
        }

        ManagerHierarchy* get_common_manager(std::string employee1, std::string employee2) { 
            ManagerHierarchy *found1 = this->find(employee1);
            ManagerHierarchy *found2 = this->find(employee2); 

            if ((found1 == NULL) || (found2 == NULL)) {
                // one of the employees does not exists in the system
                return NULL;
            }

            std::vector<ManagerHierarchy*> visited1 = get_all_supervisors(employee1);
            std::vector<ManagerHierarchy*> visited2 = get_all_supervisors(employee2);;

            for (ManagerHierarchy *empl1 : visited1) { 
                for (ManagerHierarchy *empl2 : visited2) {
                    if (empl1->name == empl2->name) {
                        return empl1;
                    }
                }
            }
            return NULL;
        }

        std::string get_name() {
            return this->name;
        }
};

#endif // MANAGERHIERARCHY_HPP
