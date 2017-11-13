#include "BufferManager.h"
#include "GraphicsBuffer.h"


GraphicsBufferManager::GraphicsBufferManager()
{

}

GraphicsBufferManager::~GraphicsBufferManager()
{
	clear();
}

//http://www.cplusplus.com/reference/map/map/insert/
//Create and insert a graphics buffer
GraphicsBuffer* GraphicsBufferManager::createBuffer(const BufferObjKey key, GraphicsBuffer* bufferObj)
{
	GraphicsBuffer* p_bufferObj = NULL;
	std::map<BufferObjKey, GraphicsBuffer*>::iterator iter = m_Map.find(key);

	if (iter == m_Map.end())
	{
		p_bufferObj = bufferObj;
		m_Map[key] = p_bufferObj;
	}
	return p_bufferObj;
}

//Return desired buffer
GraphicsBuffer* GraphicsBufferManager::getBuffer(const BufferObjKey& key)
{
	std::map<BufferObjKey, GraphicsBuffer*>::iterator iter = m_Map.find(key);
	if (iter != m_Map.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}

//Delete desired buffer
void GraphicsBufferManager::deleteBuffer(const BufferObjKey& key)
{
	std::map<BufferObjKey, GraphicsBuffer*>::iterator iter = m_Map.find(key);
	if (iter != m_Map.end())
	{
		delete iter->second;
		m_Map.erase(iter);
	}
}

//Delete desired buffer (alternative)
void GraphicsBufferManager::deleteBuffer(GraphicsBuffer* unitObj)
{
	std::map<BufferObjKey, GraphicsBuffer*>::iterator iter;
	for (iter = m_Map.begin(); iter != m_Map.end(); ++iter)
		if (unitObj == iter->second)
		{
			delete unitObj;
			m_Map.erase(iter);
			return;
		}
}

//Delete all of the graphics buffers handled by the manager
void GraphicsBufferManager::clear()
{
	std::map<BufferObjKey, GraphicsBuffer*>::iterator iter;
	for (iter = m_Map.begin(); iter != m_Map.end(); ++iter)
	{
		GraphicsBuffer* p_bufferObj = iter->second;
		if (p_bufferObj != NULL)
		delete p_bufferObj;
	}
	m_Map.clear();
}
