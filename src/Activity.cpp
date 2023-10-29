#include <Activity.hpp>
#include <ActivityStack.hpp>
#include <ViewList.hpp>

Activity::Activity(ActivityStack& stack, int requestCode, Extra& extra)
    : m_stack(&stack)
    , m_viewTree(std::make_unique<ViewTree>())
    , m_context(&Context::getInstance())
{
}

Activity::~Activity()
{
}

bool Activity::draw()
{
    m_context->getWindow()->clear();
    m_context->getWindow()->draw(*m_viewTree);
    return true;
}

ViewNode* Activity::getLayer(int layer)
{
    while(m_layers.size() <= layer) {
        std::unique_ptr<ViewNode> node = std::make_unique<EmptyView>();
        m_layers.push_back(node.get());
        m_viewTree->getRoot()->attachChild(std::move(node));
    }
    
    return m_layers[layer];
}

void Activity::requestActivity(ActivityID activityID)
{
    m_stack->pushActivity(activityID);
}

void Activity::requestActivity(ActivityID activityID, int requestCode, std::unique_ptr<Extra> extra)
{
    m_stack->pushActivity(activityID, requestCode, std::move(extra));
}

void Activity::finishActivity()
{
    m_stack->backActivity();
}

void Activity::finishActivity(int resultCode, std::unique_ptr<Extra> extra)
{
    m_stack->backActivity(resultCode, std::move(extra));
}


void Activity::onActivityResult(int resultCode, std::unique_ptr<Extra> extra)
{
}