template <typename T>
class Singleton
{
    static T data;
public:
    static T* GetInstance()
    {
        return &data;
    }
};
