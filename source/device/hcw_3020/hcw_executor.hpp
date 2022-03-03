#include <map>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

class HCWEngine
    {
    public:
        HCWEngine();
        ~HCWEngine() = default;

        int HCWEnginePreRun(struct subgraph* subgraph);
        int HCWEngineRun(struct subgraph* subgraph);
        void HCWEnginePostRun();

    private:
        void ConvolutionFunc(struct node* ir_node);
        void FullyConnectionFunc(struct node* ir_node);
        void PoolingFunc(struct node* ir_node);

        //        nvdla::DataType precision = nvdla::DataType::INT8;
        //        nvdla::DataFormat inDataFormat = nvdla::DataFormat::NCHW;
        uint32_t numBatches = 1;
        std::vector<void*> inputBuffer;
        std::vector<void*> outputBuffer;
        std::vector<void*> host_buffer;
        void hcw_input_data_convert(void* dst, const void* src) const;
        void hcw_output_data_convert(void* dst, const void* src) const;
    };
