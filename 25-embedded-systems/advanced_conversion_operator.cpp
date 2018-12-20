// Expressing the idea of that a container (e.g. Array_ref) of one class
// e.g. (Circle) can be converted to a immutable container of another class (e.g. Shape) 
// holding pointer elements (Circle*, Shape*). e.g. Array_ref<Circle*> to Array_ref<Shape*>
// Programming Principles and Pracice using C++ p. 953

template<typename T>
class Array_ref {
public:
    // normal Array_ref container code

    template<typename Q>
    operator const Array_ref<const Q>()
    {
        // static implicit conversion of elements:
        static_cast<Q>(*static_cast<T*>(nullptr)); // check element conversion
        
        return Array_ref<const Q>{reinterpret_cast<Q*>(p),sz}; // convert to Array_ref
    }

    // normal Array_ref container code
};