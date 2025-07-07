std::optional<alt::ConvexPolygon2d> envelope(const alt::Polygon2d & poly) {
// Check if the input polygon is valid (not empty and has at least 3 vertices)
if (poly.vertices().size() < 3) {
return std::nullopt;
}

// Initialize min and max x and y values with the first vertex's coordinates
double minX = poly.vertices()[0].x;
double maxX = poly.vertices()[0].x;
double minY = poly.vertices()[0].y;
double maxY = poly.vertices()[0].y;

// Iterate over the remaining vertices to find the overall min and max x and y values
for (size_t i = 1; i < poly.vertices().size(); ++i) {
const auto & vertex = poly.vertices()[i];
minX = std::min(minX, vertex.x);
maxX = std::max(maxX, vertex.x);
minY = std::min(minY, vertex.y);
maxY = std::max(maxY, vertex.y);
}

// Create the axis-aligned bounding box (envelope) as a ConvexPolygon2d
alt::ConvexPolygon2d envelope;
envelope.vertices().reserve(4); // Exactly 4 vertices for a rectangle
envelope.vertices().emplace_back(minX, minY); // Bottom-Left
envelope.vertices().emplace_back(maxX, minY); // Bottom-Right
envelope.vertices().emplace_back(maxX, maxY); // Top-Right
envelope.vertices().emplace_back(minX, maxY); // Top-Left

return envelope;
}
