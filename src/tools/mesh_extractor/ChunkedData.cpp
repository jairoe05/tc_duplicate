#include "ChunkedData.h"
#include "MPQManager.h"
#include "Utils.h"

#include <string>

ChunkedData::ChunkedData( FILE* stream, uint32 maxLength, uint32 chunksHint /*= 300*/ ) :
Stream(stream)
{
    if (!Stream)
        return;
    Load(maxLength, chunksHint);
}

ChunkedData::ChunkedData( std::string file, uint32 chunksHint /*= 300*/ )
{
    Stream = MPQHandler->GetFile(file);
    if (!Stream)
        return;
    Load(0, chunksHint);
}

void ChunkedData::Load( uint32 maxLength, uint32 chunksHint )
{
    if (!maxLength)
        maxLength = Utils::Size(Stream);
    Chunks.reserve(chunksHint);
    uint32 baseOffset = ftell(Stream);
    uint32 calcOffset = 0;
    while ((calcOffset + baseOffset) < Utils::Size(Stream) && (calcOffset < maxLength))
    {
        char nameBytes[5];
        uint32 read = fread(&nameBytes, sizeof(char), 4, Stream);
        nameBytes[read] = '\0';
        std::string name = std::string(nameBytes);
        // Utils::Reverse(nameBytes);
        name = std::string(name.rbegin(), name.rend());
        uint32 length;
        fread(&length, sizeof(uint32), 1, Stream);
        calcOffset += 8;
        Chunks.push_back(new Chunk(name.c_str(), length, calcOffset + baseOffset, Stream));
        calcOffset += length;
        // save an extra seek at the end
        if ((calcOffset + baseOffset) < Utils::Size(Stream) && calcOffset < maxLength)
            fseek(Stream, length, SEEK_CUR);
    }
}

int ChunkedData::GetFirstIndex( std::string name )
{
    for (int i = 0; i < Chunks.size(); ++i)
        if (Chunks[i]->Name == name)
            return i;
    return -1;
}

Chunk* ChunkedData::GetChunkByName( std::string name )
{
    for (int i = 0; i < Chunks.size(); ++i)
        if (Chunks[i]->Name == name)
            return Chunks[i];
    return NULL;
}

ChunkedData::~ChunkedData()
{
    for (std::vector<Chunk*>::iterator itr = Chunks.begin(); itr != Chunks.end(); ++itr)
        delete *itr;

    Chunks.clear();
    if (Stream)
        fclose(Stream);
}
