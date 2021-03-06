#ifndef EXAMPLE_ANIMAL_H
#define EXAMPLE_ANIMAL_H

#include <string>

/*!
 * @defgroup animals
 * @brief This is a brief description to the animals group
 * @details Some detailed description here
 */

namespace example {
    /*!
     * @ingroup animals
     * @brief Base class for all animals from which Bird derives
     * @details Lorem Ipsum Donor. Some [Random link with **bold** and _italics_](http://github.com)
     * And the following is a \c typewritter font.
     * 
     * Example code:
     * 
     * @code
     * Animal animal = Animal("Hello World", nullptr, nullptr);
     * std::cout << animal.get_name() << std::endl;
     * @endcode
     * @see Bird
     * @bug Some random bug
     * @note Some random note
     * @warning Some random warning
     * @test Some random test description
     * @todo Some random todo
     * @tparam T Some random template paramater description which actually does not exist in the code!
     * @pre First initialize the system.
     * @date 2017-2018
     * @author Matus Novak
     * @author Hello World
     */
    class Animal {
    public:
        /*!
         * @brief The 6 classes of animal kingdom
         * @details Lorem Ipsum Donor.
         */
        enum Type {
            NONE = 0,
            INSECT = 1,
            AMPHIBIAN = 2,
            BIRD = 3,
            FISH = 4,
            REPTILE = 5,
            MAMMAL = 6
        };

        typedef std::pair<Animal*, Animal*> Parents;

        struct Result {
            const Type type = Type::NONE;
            const std::string name;
            const Animal* mother = nullptr;
            const Animal* father = nullptr;
        };

        static Animal* find_parent_by_name(Animal* child);
        static Animal* find_child_by_name(Animal* parent);

        /*!
         * @brief The main constructor
         * @details Use this constructor to allocate a new instance of Animal
         * @param type The type of the animal that matches Animal::Type
         * @param name Any name to associate the animal with
         * @exception CustomException If either only mother or father is assigned
         */
        Animal(Type type, const std::string& name, Animal* mother = nullptr, Animal* father = nullptr);
        Animal(const Animal& other) = delete;
        Animal(Animal&& animal) noexcept;
        virtual ~Animal() = default;

        void swap(Animal& other) noexcept;

        /*!
         * @brief Returns the number of limbs
         * @see get_num_of_eyes
         */
        int get_num_of_limbs() const;

        /*!
         * @brief Returns the number of eyes
         * @see get_num_of_limbs
         */
        int get_num_of_eyes() const;

        /*!
         * @brief Returns true if the animal has a tail
         * @see get_num_of_limbs
         * @retval true Does have a tail
         * @retval false Does not have a tail
         */
        bool has_tail() const;

        virtual void move();
        virtual void make_sound() = 0;

        inline Parents get_parents() const {
            return Parents(mother, father);
        }

        /*!
         * @brief Get the name of the animal
         * @returns A constant reference to the name
         */
        inline const std::string& get_name() const {
            return name;
        }

        Animal& operator = (const Animal& other) = delete;
        Animal& operator = (Animal&& other) noexcept;

        friend void some_global_function(Animal* animal);

    protected:
        /*!
         * @brief The pointer to the mother
         * @details Can be null!
         */
        Animal* mother;
        /*!
         * @brief The pointer to the father
         * @details Can be null!
         */
        Animal* father;
        std::string name;
    };

    /*!
     * @brief Some random namespace function that modifies Animal
     * @see Animal
     * @param animal The pointer to the animal instance
     */
    void some_namespace_function(Animal* animal);
}

/*!
 * @brief Some random global function that modifies Animal
 * @see Animal
 * @param animal The pointer to the animal instance
 */
extern void some_global_function(example::Animal* animal);

#endif