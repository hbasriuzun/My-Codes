// Define these to print extra informational output and warnings.
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>

using namespace arma;
using namespace mlpack;
using namespace mlpack::tree;
using namespace std;

int main()
{
  // Load the datasets.
  mat dataset;
  Row<size_t> labels;
  if (!data::Load("covertype-small.data.csv", dataset))
    throw std::runtime_error("Could not read covertype-small.data.csv!");
  if (!data::Load("covertype-small.labels.csv", labels))
    throw std::runtime_error("Could not read covertype-small.labels.csv!");

  // Labels are 1-7, but we want 0-6 (we are 0-indexed in C++).
  labels -= 1;

  // Now split the dataset into a training set and test set, using 30% of the
  // dataset for the test set.
  mat trainDataset, testDataset;
  Row<size_t> trainLabels, testLabels;
  data::Split(dataset, labels, trainDataset, testDataset, trainLabels,
      testLabels, 0.3);

  // Create the RandomForest object and train it on the training data.
  RandomForest<> r(trainDataset,
                   trainLabels,
                   7 /* number of classes */,
                   10 /* number of trees */,
                   3 /* minimum leaf size */);

  // Compute and print the training error.
  Row<size_t> trainPredictions;
  r.Classify(trainDataset, trainPredictions);
  const double trainError =
      arma::accu(trainPredictions != trainLabels) * 100.0 / trainLabels.n_elem;
  cout << "Training error: " << trainError << "%." << endl;

  // Now compute predictions on the test points.
  Row<size_t> testPredictions;
  r.Classify(testDataset, testPredictions);
  const double testError =
      arma::accu(testPredictions != testLabels) * 100.0 / testLabels.n_elem;
  cout << "Test error: " << testError << "%." << endl;
}