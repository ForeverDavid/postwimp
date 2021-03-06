#ifndef VOXELMAPDISPLAYER_WENJIRSX
#define VOXELMAPDISPLAYER_WENJIRSX

#include "VoxelMap.hpp"
#include <vector>
#include <GL/glew.h>

// display a VoxelMap.
// The voxelMap is subdivided in block of size bufferSize.
// When the voxelMap is updated, the voxelMapDisplayer
// is updating its mesh only when it is needed.

class VoxelMapDisplayer
{
    public:
        // constructor
        VoxelMapDisplayer(VoxelMap& voxelMap,uint32_t bufferSize);

        void update(PolyVox::Region region);

        // draw
        void display();
    private:
        // voxelMap
        VoxelMap& voxelMap;

        // block/buffer dimension
        int32_t bufferSize;
        int32_t nbBlockX,nbBlockY,nbBlockZ,nbBlock;
        int32_t sizeX,sizeY,sizeZ;

        // GLVertice
        struct GLVertice
        {
            glm::vec3 pos;
            glm::vec3 normal;
            glm::vec4 color;
        };

        // mesh
        struct MeshGL
        {
            GLuint vao;
            GLuint vbo;
            GLuint veo;
            uint32_t size;
            glm::vec3 translation;
        };

        // update Box
        void updateBox(uint32_t x, uint32_t y, uint32_t z);

        std::vector<MeshGL> mesh;
};

#endif /* end of include guard: VOXELMAPDISPLAYER_WENJIRSX */
