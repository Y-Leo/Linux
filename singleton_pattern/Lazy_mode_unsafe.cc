template <typename T>
class Singleton
{
    static T* inst;
public:
    static T* GetInstance()
    {
        if(inst == NULL)
            inst = new T();
        return inst;
    }
};
