#include <Windows.h>

#include <DirectXMath.h>

typedef struct D3DVERTEXELEMENT9 {
    WORD Stream;
    WORD Offset;
    BYTE Type;
    BYTE Method;
    BYTE Usage;
    BYTE UsageIndex;
} D3DVERTEXELEMENT9, *LPD3DVERTEXELEMENT9;

typedef enum D3DDECLTYPE { 
  D3DDECLTYPE_FLOAT1     = 0,
  D3DDECLTYPE_FLOAT2     = 1,
  D3DDECLTYPE_FLOAT3     = 2,
  D3DDECLTYPE_FLOAT4     = 3,
  D3DDECLTYPE_D3DCOLOR   = 4,
  D3DDECLTYPE_UBYTE4     = 5,
  D3DDECLTYPE_SHORT2     = 6,
  D3DDECLTYPE_SHORT4     = 7,
  D3DDECLTYPE_UBYTE4N    = 8,
  D3DDECLTYPE_SHORT2N    = 9,
  D3DDECLTYPE_SHORT4N    = 10,
  D3DDECLTYPE_USHORT2N   = 11,
  D3DDECLTYPE_USHORT4N   = 12,
  D3DDECLTYPE_UDEC3      = 13,
  D3DDECLTYPE_DEC3N      = 14,
  D3DDECLTYPE_FLOAT16_2  = 15,
  D3DDECLTYPE_FLOAT16_4  = 16,
  D3DDECLTYPE_UNUSED     = 17
} D3DDECLTYPE, *LPD3DDECLTYPE;

typedef enum D3DDECLMETHOD { 
  D3DDECLMETHOD_DEFAULT           = 0,
  D3DDECLMETHOD_PARTIALU          = 1,
  D3DDECLMETHOD_PARTIALV          = 2,
  D3DDECLMETHOD_CROSSUV           = 3,
  D3DDECLMETHOD_UV                = 4,
  D3DDECLMETHOD_LOOKUP            = 5,
  D3DDECLMETHOD_LOOKUPPRESAMPLED  = 6
} D3DDECLMETHOD, *LPD3DDECLMETHOD;

typedef enum D3DDECLUSAGE { 
  D3DDECLUSAGE_POSITION      = 0,
  D3DDECLUSAGE_BLENDWEIGHT   = 1,
  D3DDECLUSAGE_BLENDINDICES  = 2,
  D3DDECLUSAGE_NORMAL        = 3,
  D3DDECLUSAGE_PSIZE         = 4,
  D3DDECLUSAGE_TEXCOORD      = 5,
  D3DDECLUSAGE_TANGENT       = 6,
  D3DDECLUSAGE_BINORMAL      = 7,
  D3DDECLUSAGE_TESSFACTOR    = 8,
  D3DDECLUSAGE_POSITIONT     = 9,
  D3DDECLUSAGE_COLOR         = 10,
  D3DDECLUSAGE_FOG           = 11,
  D3DDECLUSAGE_DEPTH         = 12,
  D3DDECLUSAGE_SAMPLE        = 13
} D3DDECLUSAGE, *LPD3DDECLUSAGE;

#include "sdkmesh.h"

#include <cstdio>

const char* to_string(D3DDECLTYPE t)
{
    switch (t)
    {
    case D3DDECLTYPE_FLOAT1     : return "D3DDECLTYPE_FLOAT1";
    case D3DDECLTYPE_FLOAT2     : return "D3DDECLTYPE_FLOAT2";
    case D3DDECLTYPE_FLOAT3     : return "D3DDECLTYPE_FLOAT3";
    case D3DDECLTYPE_FLOAT4     : return "D3DDECLTYPE_FLOAT4";
    case D3DDECLTYPE_D3DCOLOR   : return "D3DDECLTYPE_D3DCOLOR ";
    case D3DDECLTYPE_UBYTE4     : return "D3DDECLTYPE_UBYTE4";
    case D3DDECLTYPE_SHORT2     : return "D3DDECLTYPE_SHORT2";
    case D3DDECLTYPE_SHORT4     : return "D3DDECLTYPE_SHORT4";
    case D3DDECLTYPE_UBYTE4N    : return "D3DDECLTYPE_UBYTE4N";
    case D3DDECLTYPE_SHORT2N    : return "D3DDECLTYPE_SHORT2N";
    case D3DDECLTYPE_SHORT4N    : return "D3DDECLTYPE_SHORT4N";
    case D3DDECLTYPE_USHORT2N   : return "D3DDECLTYPE_USHORT2N ";
    case D3DDECLTYPE_USHORT4N   : return "D3DDECLTYPE_USHORT4N ";
    case D3DDECLTYPE_UDEC3      : return "D3DDECLTYPE_UDEC3";
    case D3DDECLTYPE_DEC3N      : return "D3DDECLTYPE_DEC3N";
    case D3DDECLTYPE_FLOAT16_2  : return "D3DDECLTYPE_FLOAT16_2";
    case D3DDECLTYPE_FLOAT16_4  : return "D3DDECLTYPE_FLOAT16_4";
    case D3DDECLTYPE_UNUSED     : return "D3DDECLTYPE_UNUSED";
    }
    return "";
}

const char* to_string(D3DDECLMETHOD m)
{
    switch (m)
    {
    case D3DDECLMETHOD_DEFAULT           : return "D3DDECLMETHOD_DEFAULT";
    case D3DDECLMETHOD_PARTIALU          : return "D3DDECLMETHOD_PARTIALU";
    case D3DDECLMETHOD_PARTIALV          : return "D3DDECLMETHOD_PARTIALV";
    case D3DDECLMETHOD_CROSSUV           : return "D3DDECLMETHOD_CROSSUV";
    case D3DDECLMETHOD_UV                : return "D3DDECLMETHOD_UV";
    case D3DDECLMETHOD_LOOKUP            : return "D3DDECLMETHOD_LOOKUP";
    case D3DDECLMETHOD_LOOKUPPRESAMPLED  : return "D3DDECLMETHOD_LOOKUPPRESAMPLED";
    }
    return "";
}

const char* to_string(D3DDECLUSAGE t)
{
    switch (t)
    {
    case D3DDECLUSAGE_POSITION      : return "D3DDECLUSAGE_POSITION";
    case D3DDECLUSAGE_BLENDWEIGHT   : return "D3DDECLUSAGE_BLENDWEIGHT";
    case D3DDECLUSAGE_BLENDINDICES  : return "D3DDECLUSAGE_BLENDINDICES";
    case D3DDECLUSAGE_NORMAL        : return "D3DDECLUSAGE_NORMAL";
    case D3DDECLUSAGE_PSIZE         : return "D3DDECLUSAGE_PSIZE";
    case D3DDECLUSAGE_TEXCOORD      : return "D3DDECLUSAGE_TEXCOORD";
    case D3DDECLUSAGE_TANGENT       : return "D3DDECLUSAGE_TANGENT";
    case D3DDECLUSAGE_BINORMAL      : return "D3DDECLUSAGE_BINORMAL";
    case D3DDECLUSAGE_TESSFACTOR    : return "D3DDECLUSAGE_TESSFACTOR";
    case D3DDECLUSAGE_POSITIONT     : return "D3DDECLUSAGE_POSITIONT";
    case D3DDECLUSAGE_COLOR         : return "D3DDECLUSAGE_COLOR";
    case D3DDECLUSAGE_FOG           : return "D3DDECLUSAGE_FOG";
    case D3DDECLUSAGE_DEPTH         : return "D3DDECLUSAGE_DEPTH";
    case D3DDECLUSAGE_SAMPLE        : return "D3DDECLUSAGE_SAMPLE";
    }
    return "";
}

const char* to_string(SDKMESH_PRIMITIVE_TYPE t)
{
    switch (t)
    {
    case PT_TRIANGLE_LIST       : return "PT_TRIANGLE_LIST";
    case PT_TRIANGLE_STRIP      : return "PT_TRIANGLE_STRIP";
    case PT_LINE_LIST           : return "PT_LINE_LIST";
    case PT_LINE_STRIP          : return "PT_LINE_STRIP";
    case PT_POINT_LIST          : return "PT_POINT_LIST";
    case PT_TRIANGLE_LIST_ADJ   : return "PT_TRIANGLE_LIST_ADJ";
    case PT_TRIANGLE_STRIP_ADJ  : return "PT_TRIANGLE_STRIP_ADJ";
    case PT_LINE_LIST_ADJ       : return "PT_LINE_LIST_ADJ";
    case PT_LINE_STRIP_ADJ      : return "PT_LINE_STRIP_ADJ";
    case PT_QUAD_PATCH_LIST     : return "PT_QUAD_PATCH_LIST";
    case PT_TRIANGLE_PATCH_LIST : return "PT_TRIANGLE_PATCH_LIST";
    }
    return "";
}

const char* to_string(SDKMESH_INDEX_TYPE t)
{
    switch (t)
    {
    case IT_16BIT: return "IT_16BIT";
    case IT_32BIT: return "IT_32BIT";
    }
    return "";
}

int main()
{
    FILE* f = fopen("cube.sdkmesh", "rb");
    fseek(f, 0L, SEEK_END);
    long sz = ftell(f);
    rewind(f);

    char* data = new char[sz];
    fread(data, 1, sz, f);
    fclose(f);

    SDKMESH_HEADER* header = (SDKMESH_HEADER*)data;
    printf("SDKMESH_HEADER:\n");
    printf("  Version: %u\n", header->Version);
    printf("  IsBigEndian: %u\n", header->IsBigEndian);
    printf("  HeaderSize: 0x%llx\n", header->HeaderSize);
    printf("  NonBufferDataSize: 0x%llx\n", header->NonBufferDataSize);
    printf("  BufferDataSize: 0x%llx\n", header->BufferDataSize);
    printf("  NumVertexBuffers: %u\n", header->NumVertexBuffers);
    printf("  NumIndexBuffers: %u\n", header->NumIndexBuffers);
    printf("  NumMeshes: %u\n", header->NumMeshes);
    printf("  NumTotalSubsets: %u\n", header->NumTotalSubsets);
    printf("  NumFrames: %u\n", header->NumFrames);
    printf("  NumMaterials: %u\n", header->NumMaterials);
    printf("  VertexStreamHeaderOffset: 0x%llx\n", header->VertexStreamHeadersOffset);
    printf("  IndexStreamHeadersOffset: 0x%llx\n", header->IndexStreamHeadersOffset);
    printf("  MeshDataOffset: 0x%llx\n", header->MeshDataOffset);
    printf("  SubsetDataOffset: 0x%llx\n", header->SubsetDataOffset);
    printf("  FrameDataOffset: 0x%llx\n", header->FrameDataOffset);
    printf("  MaterialDataOffset: 0x%llx\n", header->MaterialDataOffset);

    for (UINT i = 0; i < header->NumVertexBuffers; i++)
    {
        SDKMESH_VERTEX_BUFFER_HEADER* vheader = (SDKMESH_VERTEX_BUFFER_HEADER*)(data + header->VertexStreamHeadersOffset) + i;

        printf("SDKMESH_VERTEX_BUFFER_HEADER(%u):\n", i);
        printf("  NumVertices: %llu\n", vheader->NumVertices);
        printf("  SizeBytes: 0x%llx\n", vheader->SizeBytes);
        printf("  StrideBytes: 0x%llx\n", vheader->StrideBytes);
        for (D3DVERTEXELEMENT9* decl = vheader->Decl; decl->Stream != 255; decl++)
        {
            printf("  Decl(%u):\n", (unsigned int)(decl - vheader->Decl));
            printf("    Stream: %u\n", decl->Stream);
            printf("    Offset: %u\n", decl->Offset);
            printf("    Type: %s\n", to_string((D3DDECLTYPE)decl->Type));
            printf("    Method: %s\n", to_string((D3DDECLMETHOD)decl->Method));
            printf("    Usage: %s\n", to_string((D3DDECLUSAGE)decl->Usage));
            printf("    UsageIndex: %u\n", decl->UsageIndex);
        }
        printf("  DataOffset: 0x%llx\n", vheader->DataOffset);
    }
    
    for (UINT i = 0; i < header->NumIndexBuffers; i++)
    {
        SDKMESH_INDEX_BUFFER_HEADER* iheader = (SDKMESH_INDEX_BUFFER_HEADER*)(data + header->IndexStreamHeadersOffset) + i;

        printf("SDKMESH_INDEX_BUFFER_HEADER(%u)\n", i);
        printf("  NumIndices: %llu\n", iheader->NumIndices);
        printf("  SizeBytes: 0x%llx\n", iheader->SizeBytes);
        printf("  IndexType: %s\n", to_string((SDKMESH_INDEX_TYPE)iheader->IndexType));
        printf("  DataOffset: 0x%llx\n", iheader->DataOffset);
    }

    for (UINT i = 0; i < header->NumMeshes; i++)
    {
        SDKMESH_MESH* mesh = (SDKMESH_MESH*)(data + header->MeshDataOffset) + i;

        printf("SDKMESH_MESH(%u)\n", i);
        printf("  Name: %s\n", mesh->Name);
        printf("  NumVertexBuffers: %u\n", mesh->NumVertexBuffers);
        printf("  VertexBuffers: {");
        for (BYTE b = 0; b < mesh->NumVertexBuffers; b++)
        {
            printf(" %u", mesh->VertexBuffers[b]);
        }
        printf(" }\n");
        printf("  IndexBuffer: %u\n", mesh->IndexBuffer);
        printf("  NumSubsets: %u\n", mesh->NumSubsets);
        printf("  NumFrameInfluences: %u\n", mesh->NumFrameInfluences);
        printf("  BoundingBoxCenter: { %f, %f, %f }\n", mesh->BoundingBoxCenter.x, mesh->BoundingBoxCenter.y, mesh->BoundingBoxCenter.z);
        printf("  BoundingBoxExtents: { %f, %f, %f }\n", mesh->BoundingBoxExtents.x, mesh->BoundingBoxExtents.y, mesh->BoundingBoxExtents.z);
        printf("  SubsetOffset: 0x%llx\n", mesh->SubsetOffset);
        printf("  FrameInfluenceOffset: 0x%llx\n", mesh->FrameInfluenceOffset);
    }

    for (UINT i = 0; i < header->NumTotalSubsets; i++)
    {
        SDKMESH_SUBSET* subset = (SDKMESH_SUBSET*)(data + header->SubsetDataOffset) + i;

        printf("SDKMESH_SUBSET(%u)\n", i);
        printf("  Name: %s\n", subset->Name);
        printf("  MaterialID: %u\n", subset->MaterialID);
        printf("  PrimitiveType: %s\n", to_string((SDKMESH_PRIMITIVE_TYPE)subset->PrimitiveType));
        printf("  IndexStart: %llu\n", subset->IndexStart);
        printf("  IndexCount: %llu\n", subset->IndexCount);
        printf("  VertexStart: %llu\n", subset->VertexStart);
        printf("  VertexCount: %llu\n", subset->VertexCount);
    }

    for (UINT i = 0; i < header->NumFrames; i++)
    {
        SDKMESH_FRAME* frame = (SDKMESH_FRAME*)(data + header->FrameDataOffset) + i;

        printf("SDKMESH_FRAME(%u)\n", i);
        printf("  Name: %s\n", frame->Name);
        printf("  Mesh: %u\n", frame->Mesh);
        printf("  ParentFrame: %u\n", frame->ParentFrame);
        printf("  ChildFrame: %u\n", frame->ChildFrame);
        printf("  SiblingFrame: %u\n", frame->SiblingFrame);
        printf("  Matrix:\n");
        printf("    { %f, %f, %f, %f }\n", frame->Matrix.m[0][0], frame->Matrix.m[0][1], frame->Matrix.m[0][2], frame->Matrix.m[0][3]);
        printf("    { %f, %f, %f, %f }\n", frame->Matrix.m[1][0], frame->Matrix.m[1][1], frame->Matrix.m[1][2], frame->Matrix.m[1][3]);
        printf("    { %f, %f, %f, %f }\n", frame->Matrix.m[2][0], frame->Matrix.m[2][1], frame->Matrix.m[2][2], frame->Matrix.m[2][3]);
        printf("    { %f, %f, %f, %f }\n", frame->Matrix.m[3][0], frame->Matrix.m[3][1], frame->Matrix.m[3][2], frame->Matrix.m[3][3]);
        printf("  AnimationDataIndex: %u\n", frame->AnimationDataIndex);
    }

    for (UINT i = 0; i < header->NumMaterials; i++)
    {
        SDKMESH_MATERIAL* material = (SDKMESH_MATERIAL*)(data + header->MaterialDataOffset) + i;

        printf("SDKMESH_MATERIAL(%u)\n", i);
        printf("  Name: %s\n", material->Name);
        printf("  MaterialInstancePath: %s\n", material->MaterialInstancePath);
        printf("  DiffuseTexture: %s\n", material->DiffuseTexture);
        printf("  NormalTexture: %s\n", material->NormalTexture);
        printf("  SpecularTexture: %s\n", material->SpecularTexture);
        printf("  Diffuse: { %f, %f, %f, %f }\n", material->Diffuse.x, material->Diffuse.y, material->Diffuse.z, material->Diffuse.w);
        printf("  Ambient: { %f, %f, %f, %f }\n", material->Ambient.x, material->Ambient.y, material->Ambient.z, material->Ambient.w);
        printf("  Specular: { %f, %f, %f, %f }\n", material->Specular.x, material->Specular.y, material->Specular.z, material->Specular.w);
        printf("  Emissive: { %f, %f, %f, %f }\n", material->Emissive.x, material->Emissive.y, material->Emissive.z, material->Emissive.w);
        printf("  Power: %f\n", material->Power);
    }
}