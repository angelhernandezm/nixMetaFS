//
// Created by angel on 27/06/19.
//

#ifndef NIXMETAFS_LINQCORE_H
#define NIXMETAFS_LINQCORE_H

#include "../Common.h"

namespace nixMetaFS {
    namespace Core {
        template<class T>
        class LinqCore {
        public:
            /*
             * Filters a sequence of values based on a predicate
             */
            static std::vector<T> Where(std::vector<T> collection, std::function<bool(T)> condition) {
                std::vector<T> retval;

                if (collection.size() > 0 && condition != nullptr) {
                    for (auto &p : collection) {
                        if (condition(p))
                            retval.push_back(p);
                    }
                }

                return retval;
            }

            /*
             * Returns a specified number of contiguous elements from the start of a sequence
             */
            static std::vector<T> Take(std::vector<T> collection, int count, std::function<bool(T)> condition) {
                auto index = 0;
                std::vector<T> retval;
                count = count < 0 ? 1 : count;

                if (collection.size() > 0 && condition != nullptr) {
                    for (auto &p : collection) {
                        if (condition(p)) {
                            retval.push_back(p);
                            if (++index == count)
                                break;
                        }
                    }
                }

                return retval;
            }

            /*
             * Returns a number that represents how many elements in the specified sequence satisfy a condition
             */
            static int Count(std::vector<T> collection, std::function<bool(T)> condition) {
                auto retval = 0;

                if (collection.size() > 0 && condition != nullptr) {
                    for (auto &p : collection) {
                        if (condition(p))
                            retval++;
                    }
                }
                return retval;
            }

            /*
             * Computes the average of a sequence of Decimal or Float values
             */
            static T Average(std::vector<T> collection) {
                long length = 0;
                T retval = 0, sum = 0;
                auto type = std::string(typeid(T).name());

                // we process float and double only
                if (type == "f" || type == "d") {
                    if ((length = collection.size()) > 0) {
                        for (auto &p : collection) {
                            sum += p;
                        }
                        retval = sum / length;
                    }
                }

                return retval;
            }

            /*
             * Casts the elements of an array to a std::vector
             */
            static std::vector<T> Cast(T source[], int size) {
                std::vector<T> retval;

                try {
                    for (auto index = 0; index < size; index++)
                        retval.push_back(source[index]);
                } catch (std::exception &ex) {
                    // just to handle any undefined behavior (e.g.: such as bad::alloc)
                }

                return retval;
            }

            /*
             * Returns the maximum value in a sequence of Float, Decimal or Integer values
             */
            static T Max(std::vector<T> collection) {
                T retval = 0;
                auto type = std::string(typeid(T).name());
                auto comparison = [&](T a, T b) -> bool { return a < b; };

                // we process float, double and integer only
                if (type == "f" || type == "d" || type == "i") {
                    retval = *std::max_element(collection.begin(), collection.end(), comparison);
                }

                return retval;
            }

            /*
             * Returns the minimum value in a sequence of Float, Decimal or Integer values
             */
            static T Min(std::vector<T> collection) {
                T retval = 0;
                auto type = std::string(typeid(T).name());
                auto comparison = [&](T a, T b) -> bool { return a < b; };

                // we process float, double and integer only
                if (type == "f" || type == "d" || type == "i") {
                    retval = *std::min_element(collection.begin(), collection.end(), comparison);
                }

                return retval;
            }

            /*
             * Computes the sum of a sequence of Float, Decimal or Integer values.
             */
            static T Sum(std::vector<T> collection) {
                T retval = 0;
                auto type = std::string(typeid(T).name());

                // we process float, double and integer only
                if (type == "f" || type == "d" || type == "i") {
                    if (collection.size() > 0) {
                        for (auto &p : collection) {
                            retval += p;
                        }
                    }
                }

                return retval;
            }
        };
    }
}


#endif //NIXMETAFS_LINQCORE_H
