#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <fstream>
#include <opencv2/opencv.hpp>

// Huffman ağacı düğümü
struct HuffmanNode {
    uchar data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(uchar data, int freq) {
        this->data = data;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Ağaç düğümlerini frekanslarına göre karşılaştırmak için özel karşılaştırıcı sınıf
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;
    }
};

// Huffman ağacını oluşturmak için yardımcı fonksiyon
HuffmanNode* buildHuffmanTree(std::map<uchar, int>& freqMap) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;

    for (const auto& entry : freqMap) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode(0, left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

// Huffman kod tablosunu oluşturmak için yardımcı fonksiyon
void buildHuffmanTable(HuffmanNode* root, std::string code, std::map<uchar, std::string>& huffmanTable) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanTable[root->data] = code;
    }

    buildHuffmanTable(root->left, code + "0", huffmanTable);
    buildHuffmanTable(root->right, code + "1", huffmanTable);
}

void compressImageWithHuffman(const cv::Mat& inputImage, const std::string& compressedFilePath) {
    std::map<uchar, int> freqMap;

    // Görüntüyü taramak ve piksel değerlerini frekans haritasında toplamak
    for (int row = 0; row < inputImage.rows; row++) {
        for (int col = 0; col < inputImage.cols; col++) {
            uchar pixelValue = inputImage.at<uchar>(row, col);
            freqMap[pixelValue]++;
        }
    }

    // Huffman ağacını oluştur
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // Huffman kod tablosunu oluştur
    std::map<uchar, std::string> huffmanTable;
    buildHuffmanTable(root, "", huffmanTable);

    // Görüntüyü kodlayarak sıkıştır
    std::string compressedData;
    for (int row = 0; row < inputImage.rows; row++) {
        for (int col = 0; col < inputImage.cols; col++) {
            uchar pixelValue = inputImage.at<uchar>(row, col);
            compressedData += huffmanTable[pixelValue];
        }
    }

    // Sıkıştırılmış veriyi dosyaya yaz
    std::ofstream outputFile(compressedFilePath, std::ios::out | std::ios::binary);
    if (outputFile.is_open()) {
        // Huffman ağacının yapısını sıkıştırılmış dosyanın başına ekleyebilirsiniz
        // Burada sadece sıkıştırılmış veriyi dosyaya yazıyoruz.
        outputFile << compressedData;
        outputFile.close();
    }
}


int main() {
    // Sıkıştırılacak görüntünün yolunu belirleyin
    std::string inputImagePath = "Resources/lambo.png";

    // Görüntüyü oku
    cv::Mat inputImage = cv::imread(inputImagePath, cv::IMREAD_GRAYSCALE);
    if (inputImage.empty()) {
        std::cerr << "Error: Failed to load the input image." << std::endl;
        return -1;
    }

    // Sıkıştırılmış dosyanın yolu ve adını belirleyin
    std::string compressedFilePath = "Resources/image.bin";

    // Huffman kodlama ile görüntüyü sıkıştır
    compressImageWithHuffman(inputImage, compressedFilePath);

    return 0;
}
