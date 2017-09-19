#include "linkmanager.h"

LinkManager::LinkManager(std::vector<std::shared_ptr<mlink>> *links_)
{
    // store the pointer to the links struct
    links = links_;
    std::cout << "LinkManager constructing" << std::endl;
}

LinkManager::~LinkManager()
{
    std::cout << "LinkManager Destructing" << std::endl;
}

bool LinkManager::hasPending()
{
    if(links_to_add.read_available() != 0)
        return true;

    if(links_to_remove.read_available() != 0)
        return true;

    return false;
}

void LinkManager::operate()
{
    std::cout << "LinkManager Operating" << std::endl;
}

int LinkManager::addSerial(serial_properties properties, LinkOptions options)
{
    std::cout << "LinkManager: Creating Serial Link" << std::endl;
    int link_id_ = newLinkID();
    links->push_back(std::shared_ptr<mlink>(new serial(properties,link_id_,options)));
    return link_id_;
}

int LinkManager::addUDP(udp_properties properties, LinkOptions options)
{
    std::cout << "LinkManager: Creating UDP Link" << std::endl;
    int link_id_ = newLinkID();
    links->push_back(std::shared_ptr<mlink>(new asyncsocket(properties,link_id_,options)));
    return link_id_;
}

bool LinkManager::removeLink()
{
    std::cout << "LinkManager: Coming soon" << std::endl;
}

int LinkManager::newLinkID()
{
    return link_id_counter++;
}