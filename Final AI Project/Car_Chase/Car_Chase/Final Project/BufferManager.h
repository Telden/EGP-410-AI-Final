#pragma once
#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include <map>
#include <Trackable.h>
#include <string>


class GraphicsBuffer;
const typedef std::string BufferObjKey;

class GraphicsBufferManager : public Trackable
{
public:
	
	GraphicsBufferManager();
	~GraphicsBufferManager();

	GraphicsBuffer* createBuffer(const BufferObjKey key, GraphicsBuffer* bufferObj);
	GraphicsBuffer* getBuffer(const BufferObjKey& key);
	void deleteBuffer(const BufferObjKey& key);
	void deleteBuffer(GraphicsBuffer* unitObj);
	void clear();

private:

	std::map<BufferObjKey, GraphicsBuffer*> m_Map;

};



#endif