#include <iostream>
#include <string_view>

class SocialNetworkConnector
{
public:
    virtual ~SocialNetworkConnector() = default;
    virtual void logIn() const = 0;
    virtual void logOut() const = 0;
    virtual void createPost(std::string_view content) const = 0;
};

class FacebookConnector : public SocialNetworkConnector
{
private:
    std::string user{};
    std::string password{};

public:
    FacebookConnector(std::string_view user, std::string_view password)
    {
        this->user = user;
        this->password = password;
    }

    void logIn() const override
    {
        std::cout << "Send HTTP API request to log in user " << this->user << " with password "
                  << this->password << '\n';
    }
    void logOut() const override
    {
        std::cout << "Send HTTP API request to log out user " << this->user << '\n';
    }
    void createPost(std::string_view content) const override
    {
        std::cout << "Send HTTP API requests to create a post in Facebook timeline with content { " << content << " }\n";
    }
};

class LinkedInConnector : public SocialNetworkConnector
{
private:
    std::string user{};
    std::string password{};

public:
    LinkedInConnector(std::string_view user, std::string_view password)
    {
        this->user = user;
        this->password = password;
    }

    void logIn() const override
    {
        std::cout << "Send HTTP API request to log in user " << this->user << " with password "
                  << this->password << '\n';
    }
    void logOut() const override
    {
        std::cout << "Send HTTP API request to log out user " << this->user << '\n';
    }
    void createPost(std::string_view content) const override
    {
        std::cout << "Send HTTP API requests to create a post in LinkedIn timeline with content { " << content << " }\n";
    }
};

class SocialNetworkPoster
{
public:
    virtual ~SocialNetworkPoster() = default;
    virtual SocialNetworkConnector *getSocialNetwork() const = 0;
    void post(std::string_view content) const
    {
        SocialNetworkConnector *network{this->getSocialNetwork()};
        network->logIn();
        network->logOut();
        network->createPost(content);
        delete network;
    }
};

class FacebookPoster : public SocialNetworkPoster
{
private:
    std::string user{};
    std::string password{};

public:
    FacebookPoster(std::string_view user, std::string_view password)
    {
        this->user = user;
        this->password = password;
    }

    SocialNetworkConnector *getSocialNetwork() const
    {
        return new FacebookConnector(this->user, this->password);
    }
};

class LinkedInPoster : public SocialNetworkPoster
{
private:
    std::string user{};
    std::string password{};

public:
    LinkedInPoster(std::string_view user, std::string_view password)
    {
        this->user = user;
        this->password = password;
    }

    SocialNetworkConnector *getSocialNetwork() const
    {
        return new LinkedInConnector(this->user, this->password);
    }
};

void clientCode(const SocialNetworkPoster &network)
{
    network.post("Hello world!");
    network.post("I had a large hamburger this morning!");
}

int main()
{
    std::cout << "Testing ConcreteCreator1:\n";
    SocialNetworkPoster *facebook{new FacebookPoster("john_smith", "******")};
    clientCode(*facebook);
    std::cout << std::endl;
    std::cout << "Testing ConcreteCreator2:\n";
    SocialNetworkPoster *linkedIn{new LinkedInPoster("john_smith@example.com", "******")};
    clientCode(*linkedIn);
    std::cout << std::endl;

    delete facebook;
    delete linkedIn;
}